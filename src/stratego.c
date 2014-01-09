#include "stratego.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <time.h>
#include <math.h>

#include "Referee.h"
#include "GUI.h"

//Definitions
//*********************************************
        //Attributs
        //*************************************
        char pathIA1[300];
        char pathIA2[300];
        
        pfInitLibrary j1InitLibrary;
        pfStartMatch j1StartMatch;
        pfStartGame j1StartGame;
        pfEndGame j1EndGame;
        pfEndMatch j1EndMatch;
        pfNextMove j1NextMove;
        pfAttackResult j1AttackResult;
        pfPenalty j1Penalty;

        pfInitLibrary j2InitLibrary;
        pfStartMatch j2StartMatch;
        pfStartGame j2StartGame;
        pfEndGame j2EndGame;
        pfEndMatch j2EndMatch;
        pfNextMove j2NextMove;
        pfAttackResult j2AttackResult;
        pfPenalty j2Penalty;
        
        int nbPlayers;
        char j1Name[50];
        char j2Name[50];
        EColor j1Color;
        EColor j2Color;
        int nbMaxCps = 0;
        int j1NbPenalty = 0;
        int j2NbPenalty = 0;
        
        
        //Fonctions
        //*************************************
     
        //Affiche le plateau dans la console
        void PrintBoard(const SGameState * const gameState);
        void PrintLine();
        
        EColor GetRandomColor();
        
        int LoadLibraries();
        
        void GameStateCpy(SGameState *game,SGameState *cpy);
        void ExecuteMove(SGameState *game,SMove move,EColor color);
        
        void RevertGame(SGameState *game);
        void HideColor(SGameState *game,EColor color);
        
        void CheckCommand();
        SGameState* CreateBoard();
        void SetPlayerColors();


        
//Implementations
//*********************************************
        //Affiche une ligne dans la console (Utilisé pour l'affichage du jeu dans la console)
        void PrintLine(){
            int i;
            for(i=0;i<63;i++){
                printf("-");
            }
            printf("\n");
        }

        //Affiche l'état courant du jeu dans la console
        void PrintBoard(const SGameState * const gameState){
            if( gameState ) {
                int i,j;
                //affichage nombres colonnes
                printf("  |");
                for(i=0;i<10;i++){
                    printf("  %d  |",i);
                }
                printf("\n");
                PrintLine();
                for(i=0;i<10;i++){
                    printf("%d |",i);
                    for(j=0;j<10;j++){
                        int content = gameState->board[i][j].content;
                        int piece = gameState->board[i][j].piece;
                        char sign = 'B';
                        if( content == EClake ){sign = 'X';}
                        else if(content == ECnone ){sign = ' ';}
                        else if(content == ECred ){sign = 'R';}
                        
                        if( piece == 12 && content == 1 ){ printf("  %c  |",sign); }
                        else if( piece == 12 && content == 0){ printf("     |"); }
                        else if( piece==10 ){ printf(" %c%d |",sign,piece); }
                        else if( piece==11 ){ printf("  %cF |",sign); }
                        else{ printf("  %c%d |",sign,piece); }
                    }
                    printf("\n");
                    PrintLine();
                }
            }
        }

        EColor GetRandomColor()
        {
            EColor choice = (EColor) (rand()%2)+2;
            return choice;
        }
        
        int LoadLibraries()
        {
            // Chargement de la librairie (chargement des pointeurs de fonctions des fonctions décrites dans "stratego.h")
            //Si il y a au moins 1 IA 
            if( nbPlayers < 2 ){
                void *lib;
                //Initialisation de la première IA
                if( (lib=dlopen(pathIA1,RTLD_LAZY))==NULL){ printf("IA 1 : loading Failed\n");return(0); }
                    if( (j1InitLibrary=(pfInitLibrary) dlsym(lib,"InitLibrary"))==NULL){ printf("IA 1 : loading 'InitLibrary' Failed\n");return(0); }
                    if( (j1StartMatch=(pfStartMatch) dlsym(lib,"StartMatch"))==NULL){ printf("IA 1 : loading 'StartMatch' Failed\n");return(0); }
                    if( (j1StartGame=(pfStartGame) dlsym(lib,"StartGame"))==NULL){ printf("IA 1 : loading 'StartGame' Failed\n");return(0); }
                    if( (j1EndGame=(pfEndGame) dlsym(lib,"EndGame"))==NULL){ printf("IA 1 : loading 'EndGame' Failed\n");return(0); }
                    if( (j1EndMatch=(pfEndMatch) dlsym(lib,"EndMatch"))==NULL){ printf("IA 1 : loading 'EndMatch' Failed\n");return(0); }
                    if( (j1NextMove=(pfNextMove) dlsym(lib,"NextMove"))==NULL){ printf("IA 1 : loading 'NextMove' Failed\n");return(0); }
                    if( (j1AttackResult=(pfAttackResult) dlsym(lib,"AttackResult"))==NULL){ printf("IA 1 : loading 'AttackResult' Failed\n");return(0); }
                    if( (j1Penalty=(pfPenalty) dlsym(lib,"Penalty"))==NULL){ printf("IA 1 : loading 'Penalty' Failed\n");return(0); }
                    printf("IA 1 : %s loaded\n",pathIA1);
                if( nbPlayers == 0 ){
                    if( (lib=dlopen(pathIA2,RTLD_LAZY))==NULL){ printf("IA 2 : loading Failed\n");return(0); }
                    if( (j2InitLibrary=(pfInitLibrary) dlsym(lib,"InitLibrary"))==NULL){ printf("IA 2 : loading 'InitLibrary' Failed\n");return(0); }
                    if( (j2StartMatch=(pfStartMatch) dlsym(lib,"StartMatch"))==NULL){ printf("IA 2 : loading 'StartMatch' Failed\n");return(0); }
                    if( (j2StartGame=(pfStartGame) dlsym(lib,"StartGame"))==NULL){ printf("IA 2 : loading 'StartGame' Failed\n");return(0); }
                    if( (j2EndGame=(pfEndGame) dlsym(lib,"EndGame"))==NULL){ printf("IA 2 : loading 'EndGame' Failed\n");return(0); }
                    if( (j2EndMatch=(pfEndMatch) dlsym(lib,"EndMatch"))==NULL){ printf("IA 2 : loading 'EndMatch' Failed\n");return(0); }
                    if( (j2NextMove=(pfNextMove) dlsym(lib,"NextMove"))==NULL){ printf("IA 2 : loading 'NextMove' Failed\n");return(0); }
                    if( (j2AttackResult=(pfAttackResult) dlsym(lib,"AttackResult"))==NULL){ printf("IA 2 : loading 'AttackResult' Failed\n");return(0); }
                    if( (j2Penalty=(pfPenalty) dlsym(lib,"Penalty"))==NULL){ printf("IA 2 : loading 'Penalty' Failed\n");return(0); }
                    printf("IA 2 : %s loaded\n",pathIA2);
                    return 1;
                }
            }
            // Sinon chargement du 1er joueur graphique
            else{
                j1InitLibrary = j1InitPlayer_GUI;
                j1StartMatch = j1StartMatch_GUI;
                j1StartGame = j1StartGame_GUI;
                j1EndGame = j1EndGame_GUI;
                j1EndMatch = j1EndMatch_GUI; 
                j1NextMove = j1NextMove_GUI;
                j1AttackResult = j1AttackResult_GUI;
                j1Penalty = j1Penalty_GUI;
            }
            //Chargement du deuxième joueur graphique car situation ou il y a 2 joueurs graphiques
            j2InitLibrary = j2InitPlayer_GUI;
            j2StartMatch = j2StartMatch_GUI;
            j2StartGame = j2StartGame_GUI;
            j2EndGame = j2EndGame_GUI;
            j2EndMatch = j2EndMatch_GUI; 
            j2NextMove = j2NextMove_GUI;
            j2AttackResult = j2AttackResult_GUI;
            j2Penalty = j2Penalty_GUI;
            
            return 1;
        }
        
        void GameStateCpy(SGameState *game,SGameState *cpy)
        {
            int i,j;
            for(i=0;i<11;i++){
                cpy->blueOut[i] = game->blueOut[i];
                cpy->redOut[i] = game->redOut[i];
            }

            for(i=0;i<10;i++){
                for(j=0;j<10;j++){
                    cpy->board[i][j].content = game->board[i][j].content;
                    cpy->board[i][j].piece = game->board[i][j].piece;
                }
            }
            
        }
        
        void ExecuteMove(SGameState *game,SMove move,EColor color)
        {
            if( game && color>1 && color<=3 ){
                //Si c'est le joueur rouge on inverse les indices du mouvement pour l'adapter au plateau
                if( color == ECred ){
                    move.start.line = 9 -  move.start.line;
                    move.end.line = 9 - move.end.line;
                }
                
                SBox start = game->board[move.start.line][move.start.col];
                SBox end = game->board[move.end.line][move.end.col];
                if( end.content == 0 ){
                    game->board[move.end.line][move.end.col].content = color;
                    game->board[move.end.line][move.end.col].piece = start.piece;
                }
                else{
                    if( start.piece > end.piece ){
                        //l'ennemi a perdu on l'ajoute au tableau des pièces sorties
                        if( color == ECred ){ game->blueOut[end.piece]++; }
                        else{ game->redOut[end.piece]++; }

                        //l'attaquant a battu l'ennemi
                        game->board[move.end.line][move.end.col].content = color;
                        game->board[move.end.line][move.end.col].piece = start.piece;
                    }
                    else if( start.piece < end.piece ){
                        if( color == ECred ){ game->redOut[end.piece]++; }
                        else{ game->blueOut[end.piece]++; }
                    }
                    else{
                        //Les deux pièces sont éliminées
                        game->redOut[end.piece]++;
                        game->blueOut[end.piece]++;

                        game->board[move.end.line][move.end.col].content = ECnone;
                        game->board[move.end.line][move.end.col].piece = EPnone;
                    }
                }
                game->board[move.start.line][move.start.col].content = ECnone;
                game->board[move.start.line][move.start.col].piece = EPnone; 
            }
        }
        
        void RevertGame(SGameState *game)
        {
            int i,j;
            for(i=0;i<5;i++){
                for(j=0;j<10;j++){
                    int tmpC = game->board[i][j].content;
                    int tmpP = game->board[i][j].piece;
                    game->board[i][j].content = game->board[9-i][j].content;
                    game->board[i][j].piece = game->board[9-i][j].piece;
                    game->board[9-i][j].content = tmpC;
                    game->board[9-i][j].piece = tmpP;
                }
            }
        }
        
        void HideColor(SGameState *game,EColor color)
        {
            if( color == 2 || color == 3 ){
                int i,j;
                for(i=0;i<10;i++){
                    for(j=0;j<10;j++){
                        if( game->board[i][j].content == color ){ game->board[i][j].piece = EPnone; }
                    }
                }
            }
        }
        
        void CheckCommand(int argc, char *argv[])
        {   
            if( argc == 1 ){ Menu(NULL,NULL,NULL); }
            else if( (argv[1][0]<48 || argv[1][0]>57) && argc>=3){ 
                nbPlayers = 0;
                
                strcpy( pathIA1, argv[1]);
                strcpy( pathIA2, argv[2]);
                
                Menu(NULL,argv[1],argv[2]);
            }
            else{ 
                //Recherche du nombre max de coups
                int i;
                for(i=0; argv[1][i] != '\0';i++){
                    nbMaxCps *= 10;
                    nbMaxCps += argv[1][i] - '0';
                }
                
                if( argc == 2 ){
                    // Player vs Player
                    nbPlayers = 2;
                    printf("Player vs Player\n");
                }
                else if( argc == 3 ){
                    // Player vs IA
                    nbPlayers = 1;
                    
                    strcpy( pathIA1, argv[2]);
                    
                    printf("Player vs IA\n");
                }
                else{
                    //IA vs IA
                    nbPlayers = 0;
                    strcpy( pathIA1, argv[2]);
                    strcpy( pathIA2, argv[3]);
                }
            }
        }
        
        SGameState* CreateBoard()
        {
            SGameState *gameState = (SGameState*) malloc(sizeof(SGameState));
            //Initialisation de toutes les cases à la valeur des pièces 12 (none)
            int i,j;
            for(i=0;i<10;i++){
                for(j=0;j<10;j++){
                    gameState->board[i][j].content = ECnone;
                    gameState->board[i][j].piece = EPnone;
                }
            }
            //ajout des lacs
            SBox lake;
            lake.content = EClake;
            lake.piece = EPnone;
            for(i=4;i<=5;i++){
                for(j=2;j<=6;j+=4){
                    gameState->board[i][j] = lake;
                    gameState->board[i][j+1] = lake;
                }
            }
            return gameState;
        }
        
        void SetPlayerColors()
        {
            j1Color = GetRandomColor();
            if( j1Color == ECblue ){ j2Color = ECred; }
            else{ j2Color = ECblue; }
        }
        
        //void deroulement_du_jeu()	
        int main(int argc, char *argv[] )
        {
            CheckCommand(argc,argv);
            
            //Il faut nbMaxCps pour chaques joueurs, donc on multiplie par 2
            nbMaxCps *= 2;
            
            if( !LoadLibraries() ){ return(0); }
            
            SGameState* gameState = CreateBoard();

            //Srand pour obtenir des nombres aléatoires 
            srand(time(NULL));

            //Initialisation des joueurs    
            j1InitLibrary(j1Name);   
            j2InitLibrary(j2Name);

            j1StartMatch();
            j2StartMatch();

            int nbMatch = 3;

            while( nbMatch>0 ){

                //On initialise le nombre de coups maximums
                 int cptCps = nbMaxCps;
                
                EPiece j1BoardInit[4][10];
                EPiece j2BoardInit[4][10];

                SetPlayerColors();
                
                j1StartGame(j1Color,j1BoardInit);
                j2StartGame(j2Color,j2BoardInit);

                //Initialisation des pions sur le plateau
                if( j1Color == ECblue ){
                    if( !InitBlueBoard(gameState,j1BoardInit) ){printf("mauvaise initialisation des pions de %s (Bleu)1\n",j1Name);return 0;}           
                    if( !InitRedBoard(gameState,j2BoardInit) ){printf("mauvaise initialisation des pions de %s (Rouge)\n",j2Name);return 0;}
                }
                else{
                    if( !InitRedBoard(gameState,j1BoardInit) ){printf("mauvaise initialisation des pions de %s (Rouge)\n",j1Name);return 0;}
                    if( !InitBlueBoard(gameState,j2BoardInit) ){printf("mauvaise initialisation des pions de %s (Bleu)\n",j2Name);return 0;}
                }

                //Le premier joueur est le rouge
                EColor player = ECred;

                EColor winner = 0;
                
                PrintBoard(gameState);
                printf("******************************************\n");
                
                
                while( !winner && cptCps>0 ){

                    SMove move;
                    
                    //Duplication du plateau
                    SGameState *gameStateCpy = (SGameState*) malloc(sizeof(SGameState));
                    GameStateCpy(gameState,gameStateCpy);
                    
                    //Si c'est le tour du joueur rouge, on inverse son plateau 
                    if( player == ECred ){
                        RevertGame(gameStateCpy);
                    }

                    //On cache les pions du joueur ennemi
                    HideColor(gameStateCpy,abs((player+1)%2)+2);
                    
                    if( player == j1Color ){ move = j1NextMove(gameStateCpy); }
                    else{ move = j2NextMove(gameStateCpy); }

                    int moveType = CorrectMove(gameState,move);

                    //Mouvement incorrecte
                    if( moveType == 0 ){
                        if( player == j1Color ){
                            j1NbPenalty++;
                            j1Penalty();
                            if( j1NbPenalty == 3 ){
                                /* AFFICHER GAGNANT j2 puis commencer autre manche*/
                                break;
                            }
                        }
                        else{ 
                            j2NbPenalty++;
                            j2Penalty(); 
                            if( j2NbPenalty == 3 ){
                                /* AFFICHER GAGNANT j1 puis commencer autre manche*/
                                break;
                            }
                        }
                    }
                    else{
                        ExecuteMove(gameState,move,player);
                        //Attaque
                        if( moveType == 1 ){
                            EPiece army = gameState->board[move.start.line][move.start.col].piece;
                            EPiece enemy = gameState->board[move.end.line][move.end.col].piece;
                            if( player == j1Color ){
                                j1AttackResult(move.start,army,move.end,enemy);
                                j2AttackResult(move.end,enemy,move.start,army);
                            }
                            else{
                                j1AttackResult(move.end,enemy,move.start,army);
                                j2AttackResult(move.start,army,move.end,enemy);
                            }
                        }
                    }

                    free(gameStateCpy);

                    if( player == ECred ){ player = ECblue; }
                    else{ player = ECred; }

                    winner = Finished(gameState);
                    
                    cptCps--;
                    
                    PrintBoard(gameState);
                    printf("******************************************\n");
                }
                
                if( cptCps == 0){ printf("TIME'S UP!!\n");return (0); }

                nbMatch--;
                
                j1EndGame();
                j2EndGame();
            }
            j1EndMatch();
            j2EndMatch();

            free(gameState);
            return(0);
        }

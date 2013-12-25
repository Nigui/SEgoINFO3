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
        
        //Fonctions
        //*************************************
     
        //Affiche le plateau dans la console
        void PrintBoard(const SGameState * const gameState);
        void PrintLine();
        
        int InitBlueBoard(SGameState *game,EPiece boardInit[4][10]);
        int InitRedBoard(SGameState *game,EPiece boardInit[4][10]);
        
        EColor GetRandomColor();
        
        int LoadLibraries(char *argv[]);
        
        void GameStateCpy(SGameState *game,SGameState *cpy);
        void ExecuteMove(SGameState *game,SMove move,EColor color);
        
        void RevertGame(SGameState *game);
        


        
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

        int InitBlueBoard(SGameState *game,EPiece boardInit[4][10])
        {
            int listPiece[12] = {6,1,8,5,4,4,4,3,2,1,1,1};
            int i,j;
            for(i=0;i<4;i++){
                for(j=0;j<10;j++){
                    EPiece p = boardInit[i][j];
                    if( p<0 || p>12 ){printf("%d<0 || p>12\n",p);return 0;}
                    if( listPiece[p] == 0 ){printf("listPiece[%d] == 0 \n",p);return 0;}
                    else{ listPiece[p]--;}
                    game->board[i][j].piece = p;
                    game->board[i][j].content = ECblue;
                }
            }
            return 1;
        }
        
        int InitRedBoard(SGameState *game,EPiece boardInit[4][10])
        {
            int listPiece[12] = {6,1,8,5,4,4,4,3,2,1,1,1};
            int i,j;
            for(i=0;i<4;i++){
                for(j=0;j<10;j++){
                    EPiece p = boardInit[i][j];
                    if( p<0 || p>12 ){printf("%d<0 || p>12\n",p);return 0;}
                    if( listPiece[p] == 0 ){printf("listPiece[%d] == 0 \n",p);return 0;}
                    else{ listPiece[p]--;}
                    game->board[9-i][j].piece = boardInit[i][j];
                    game->board[9-i][j].content = ECred;
                }
            }
            return 1;
        }
        
        EColor GetRandomColor()
        {
            EColor choice = (EColor) (rand()%2)+2;
            return choice;
        }
        
        int LoadLibraries(char *argv[])
        {
            // Chargement de la librairie (chargement des pointeurs de fonctions des fonctions décrites dans "stratego.h")
            //Si il y a au moins 1 IA 
            if( nbPlayers < 2 ){
                void *lib;
                //Initialisation de la première IA
                if( argv[2] == 0 ){ printf("Bad command : Missing IA path\n");return(0); }
                if( (lib=dlopen(argv[2],RTLD_LAZY))==NULL){ printf("IA 1 : loading Failed\n");return(0); }
                    if( (j1InitLibrary=(pfInitLibrary) dlsym(lib,"InitLibrary"))==NULL){ printf("IA 1 : loading 'InitLibrary' Failed\n");return(0); }
                    if( (j1StartMatch=(pfStartMatch) dlsym(lib,"StartMatch"))==NULL){ printf("IA 1 : loading 'StartMatch' Failed\n");return(0); }
                    if( (j1StartGame=(pfStartGame) dlsym(lib,"StartGame"))==NULL){ printf("IA 1 : loading 'StartGame' Failed\n");return(0); }
                    if( (j1EndGame=(pfEndGame) dlsym(lib,"EndGame"))==NULL){ printf("IA 1 : loading 'EndGame' Failed\n");return(0); }
                    if( (j1EndMatch=(pfEndMatch) dlsym(lib,"EndMatch"))==NULL){ printf("IA 1 : loading 'EndMatch' Failed\n");return(0); }
                    if( (j1NextMove=(pfNextMove) dlsym(lib,"NextMove"))==NULL){ printf("IA 1 : loading 'NextMove' Failed\n");return(0); }
                    if( (j1AttackResult=(pfAttackResult) dlsym(lib,"AttackResult"))==NULL){ printf("IA 1 : loading 'AttackResult' Failed\n");return(0); }
                    if( (j1Penalty=(pfPenalty) dlsym(lib,"Penalty"))==NULL){ printf("IA 1 : loading 'Penalty' Failed\n");return(0); }
                    printf("IA 1 : %s loaded\n",argv[2]);
                if( nbPlayers == 0 ){
                    if( argv[3] == 0 ){ printf("Bad command : Missing IA path\n");return(0); }
                    if( (lib=dlopen(argv[3],RTLD_LAZY))==NULL){ printf("IA 2 : loading Failed\n");return(0); }
                    if( (j2InitLibrary=(pfInitLibrary) dlsym(lib,"InitLibrary"))==NULL){ printf("IA 2 : loading 'InitLibrary' Failed\n");return(0); }
                    if( (j2StartMatch=(pfStartMatch) dlsym(lib,"StartMatch"))==NULL){ printf("IA 2 : loading 'StartMatch' Failed\n");return(0); }
                    if( (j2StartGame=(pfStartGame) dlsym(lib,"StartGame"))==NULL){ printf("IA 2 : loading 'StartGame' Failed\n");return(0); }
                    if( (j2EndGame=(pfEndGame) dlsym(lib,"EndGame"))==NULL){ printf("IA 2 : loading 'EndGame' Failed\n");return(0); }
                    if( (j2EndMatch=(pfEndMatch) dlsym(lib,"EndMatch"))==NULL){ printf("IA 2 : loading 'EndMatch' Failed\n");return(0); }
                    if( (j2NextMove=(pfNextMove) dlsym(lib,"NextMove"))==NULL){ printf("IA 2 : loading 'NextMove' Failed\n");return(0); }
                    if( (j2AttackResult=(pfAttackResult) dlsym(lib,"AttackResult"))==NULL){ printf("IA 2 : loading 'AttackResult' Failed\n");return(0); }
                    if( (j2Penalty=(pfPenalty) dlsym(lib,"Penalty"))==NULL){ printf("IA 2 : loading 'Penalty' Failed\n");return(0); }
                    printf("IA 2 : %s loaded\n",argv[2]);
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
            if( game && cpy ){
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
            
        }
        
        void ExecuteMove(SGameState *game,SMove move,EColor color)
        {
            
            if( game && color>1 && color<=3 ){
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
        
        //void deroulement_du_jeu()	
        int main(int argc, char *argv[] )
        {
                //Check number of player
                if( argc < 2 ){
                    printf("Bad command : You have to inform number of player\n");
                    return(0);
                }
                else if( argc >= 2 ){
                    nbPlayers = *argv[1];
                    nbPlayers -= 48;                    //check int value of argv
                    if( nbPlayers > 2 || nbPlayers < 0 ){
                        printf("Bad Argument : first argument is wrong\n");
                        return(0);
                    }
                    else{
                        if( !LoadLibraries(argv) ){ return(0); }
                    }
                }

                SGameState *gameState = (SGameState*) malloc(sizeof(SGameState));
                // init de l'état de départ
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
                    PrintBoard(gameState);
                    
                //Srand pour obtenir des nombres aléatoires 
                srand(time(NULL));
                
                //Initialisation des joueurs    
                j1InitLibrary(j1Name);   
                j2InitLibrary(j2Name);
            
                j1StartMatch();
                j2StartMatch();
                
                int nbMatch = 3;
                
                while( nbMatch>0 ){
                
                    EPiece j1BoardInit[4][10];
                    EPiece j2BoardInit[4][10];
                    
                    
                    // Tirage au sort couleur 
                            EColor color = GetRandomColor();
                    j1Color = color;
                    if( j1Color == ECblue ){ j2Color = ECred; }
                    else{ j2Color = ECblue; }
                    printf("J1 Color : %d\n",j1Color);
                    printf("J2 Color : %d\n",j2Color);
                    
                    
                    j1StartGame(j1Color,j1BoardInit);
                    j2StartGame(j2Color,j2BoardInit);
                    
                    printf("New start match\n");
                    j1StartMatch();
                    j2StartMatch();
                    
                    //Initialisation des pions sur le plateau
                    if( j1Color == ECblue ){
                        if( !InitBlueBoard(gameState,j1BoardInit) ){printf("mauvaise initialisation des pions du joueur (Bleu)1\n");return 0;}           
                        if( !InitRedBoard(gameState,j2BoardInit) ){printf("mauvaise initialisation des pions du joueur 2 (Rouge)\n");return 0;}
                    }
                    else{
                        if( !InitRedBoard(gameState,j1BoardInit) ){printf("mauvaise initialisation des pions du joueur 1 (Rouge)\n");return 0;}
                        if( !InitBlueBoard(gameState,j2BoardInit) ){printf("mauvaise initialisation des pions du joueur 2 (Bleu)\n");return 0;}
                    }
                    

                    PrintBoard(gameState);
                    
                    //Le premier joueur est le rouge
                    EColor player = ECred;
                    
                    EColor winner = 0;
                    
                    printf("*************START MATCH**************\n");
                    
                    while( !winner ){
                        
                        SMove move;
                        
                        //Duplication du plateau
                        SGameState *gameStateCpy = (SGameState*) malloc(sizeof(SGameState));
                        GameStateCpy(gameState,gameStateCpy);
                        
                        //Inversement de l'état du jeu pour le joueur courant
                        RevertGame(gameStateCpy);
                        
                        PrintBoard(gameStateCpy);
                        
                        printf("DEBUG--NextMove : [  ] \n");
                        printf(" player : %d\n",player);
                        printf(" j1Color : %d\n",j1Color);
                        printf(" j2Color : %d\n",j2Color);
                        if( player == j1Color ){ printf("GO J1\n");move = j1NextMove(gameStateCpy); }
                        else{ printf("GO J2\n");move = j2NextMove(gameStateCpy); }
                        printf("DEBUG--NextMove : [OK] \n");
                        
                        int moveType = CorrectMove(gameState,move);
                        if( moveType == 0 ){
                            if( player == j1Color ){ j1Penalty(); }
                            else{ j2Penalty(); }
                        }
                        else{
                            if( moveType == 1 ){
                                //Attaque
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
                            ExecuteMove(gameState,move,player);
                        }

                        free(gameStateCpy);
                        
                        if( player == ECred ){ player = ECblue; }
                        else{ player = ECred; }
                        
                        winner = Finished(gameState);
                        
                        printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                        printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                        printf("\n");
                        PrintBoard(gameState);
                    }
                        
                    
                    nbMatch--;
                    j1EndGame();
                    j2EndGame();
                }
        	j1EndMatch();
                j2EndMatch();
                
                free(gameState);
                return(0);
        }

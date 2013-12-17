#include "stratego.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <time.h>
#include <math.h>


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
        EColor j1Color;
        EColor j2Color;
        
        //Fonctions
        //*************************************
        void PrintLine();

        //Affiche le plateau dans la console
        void PrintBoard(const SGameState * const gameState);
        
        int InitBlueBoard(SGameState *game,EPiece boardInit[4][10]);
        int InitRedBoard(SGameState *game,EPiece boardInit[4][10]);
        
        EColor GetRandomColor();
        
        int InitLibraries(char *argv[]);
        
        void GameStateCpy(SGameState *game,SGameState *cpy);
        void ExecuteMove(SGameState *game,SMove *move);
        


        
//Implementations
//*********************************************
        //Affiche une ligne dans la console (Utilisé pour l'affichage du jeu dans la console)
        void PrintLine(){
            int i;
            for(i=0;i<43;i++){
                printf("-");
            }
            printf("\n");
        }

        //Affiche l'état courant du jeu dans la console
        void PrintBoard(const SGameState * const gameState){
            int i,j;
            //affichage nombres colonnes
            printf("  |");
            for(i=0;i<10;i++){
                printf(" %d |",i);
            }
            printf("\n");
            PrintLine();
            for(i=0;i<10;i++){
                printf("%d |",i);
                for(j=0;j<10;j++){
                    int content = gameState->board[i][j].content;
                    char sign = 'B';
                    if( content == EClake ){sign = 'X';}
                    else if(content == ECnone ){sign = ' ';}
                    else if(content == ECred ){sign = 'R';}
                    printf(" %c |",sign);
                }
                printf("\n");
                PrintLine();
            }
        }

        int InitBlueBoard(SGameState *game,EPiece boardInit[4][10])
        {
            int listPiece[12] = {6,1,8,5,4,4,4,3,2,1,1,1};
            int i,j;
            for(i=0;i<4;i++){
                for(j=0;j<10;j++){
                    EPiece p = boardInit[i][j];
                    if( listPiece[p] == 0 ){return 0;}
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
                    if( listPiece[p] == 0 ){return 0;}
                    else{ listPiece[p]--;}
                    game->board[9-i][j].piece = boardInit[i][j];
                    game->board[9-i][j].content = ECred;
                }
            }
            return 1;
        }
        
        EColor GetRandomColor()
        {
            srand(time(NULL));
            EColor choice = (EColor) (rand()%2);
            return choice;
        }
        
        int InitLibraries(char *argv[])
        {
            // Chargement de la librairie (chargement des pointeurs de fonctions des fonctions décrites dans "stratego.h")
            if( nbPlayers > 0 ){
                void *lib;
                //Initialisation de la première IA
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
            
                if( nbPlayers == 2 ){
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
                }
            }
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
        
        void ExecuteMove(SGameState *game,SMove *move)
        {
            
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
                }

                SGameState *gameState = (SGameState*) malloc(sizeof(SGameState));
                // init de l'état de départ
                    //ajout des lacs
                    SBox lake;
                    lake.content = EClake;
                    lake.piece = EPnone;
                    int i,j;
                    for(i=4;i<=5;i++){
                        for(j=2;j<=6;j+=4){
                            gameState->board[i][j] = lake;
                            gameState->board[i][j+1] = lake;
                        }
                    }

                
                if( !InitLibraries(argv) ){ return(0); }

                // Initialisation de la librairie
                char j1Name[50];
                char j2Name[50];
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
                    j2Color = abs(color-1)
                    j1StartGame(j1Color,j1BoardInit);          
                    j2StartGame(j2Color,j2BoardInit);    //couleur opposée à celle choisie


                    //Initialisation des pions sur le plateau
                    if( !InitBlueBoard(gameState,j1BoardInit) ){printf("mauvaise initialisation de l'IA 1\n");return 0;}           
                    if( !InitRedBoard(gameState,j2BoardInit) ){printf("mauvaise initialisation de l'IA 2\n");return 0;}

                    PrintBoard(gameState);
                    
                    //Le premier joueur est le rouge
                    EColor player = ECred;
                            
                    while( !Finished(gameState) ){
                        
                        SMove move;
                        //Duplication du plateau
                        SGameState *gameStateCpy = (SGameState*) malloc(sizeof(SGameState));
                        GameStateCpy(gameState,gameStateCpy);
                        
                        if( player == j1Color ){ move = j1NextMove(gameStateCpy); }
                        else{ move = j2NextMove(gameStateCpy); }
                        
                        int correctMove = CorrectMove(gameState,move);
                        if( !correctMove ){
                            if( player == j1Color ){ j1Penalty(); }
                            else{ j2Penalty(); }
                        }
                        else{
                            if( correctMove == 1 ){
                                //Attaque
                                EPiece army = gameState->board[move->start.line][move->start.col].piece;
                                EPiece enemy = gameState->board[move->end.line][move->end.col].piece;
                                if( player == j1Color ){
                                    j1AttackResult(move->start,army,move->end,enemy);
                                    j2AttackResult(move->end,enemy,move->start,army);
                                }
                                else{
                                    j1AttackResult(move->end,enemy,move->start,army);
                                    j2AttackResult(move->start,army,move->end,enemy);
                                }
                            }
                            ExecuteMove(gameState,move);
                        }

                        free(gameStateCpy);
                        
                        if( player == ECred ){ player = ECblue; }
                        else{ player = ECred; }
                    }
                    
                    nbMatch--;
                    j1EndGame();
                    j2EndGame();
                }
        	j1EndMatch();
                j2EndMatch();      
                return(0);
        }

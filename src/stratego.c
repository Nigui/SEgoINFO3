#include "stratego.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <time.h>
#include <math.h>


//Definitions
//*********************************************
        void PrintLine();

        //Affiche le plateau dans la console
        void PrintBoard(const SGameState * const gameState);
        
        void InitBlueBoard(SGameState *game,EPiece boardInit[4][10]);
        void InitRedBoard(SGameState *game,EPiece boardInit[4][10]);
        
        EColor GetRandomColor();

        
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

        void InitBlueBoard(SGameState *game,EPiece boardInit[4][10])
        {
            int i,j;
            for(i=0;i<4;i++){
                for(j=0;j<10;j++){
                    game->board[i][j].piece = boardInit[i][j];
                    game->board[i][j].content = ECblue;
                }
            }
        }
        
        void InitRedBoard(SGameState *game,EPiece boardInit[4][10])
        {
            int i,j;
            for(i=0;i<4;i++){
                for(j=0;j<10;j++){
                    game->board[9-i][j].piece = boardInit[i][j];
                    game->board[9-i][j].content = ECred;
                }
            }
        }
        
        EColor GetRandomColor()
        {
            srand(time(NULL));
            EColor choice = (EColor) (rand()%2);
            return choice;
        }
        
        //void deroulement_du_jeu()	
        int main(int argc, char *argv[] )
        {
                //Check number of player
                int nbPlayers;

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

                //*****// à chaque utilisation de gameState, ne pas oublier de faire une copie de tous les éléments (pas fait ici)
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
                PrintBoard(gameState);

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

                
                // Initialisation de la librairie
                SMove move;
                char j1Name[50];
                char j2Name[50];
                j1InitLibrary(j1Name);
                j2InitLibrary(j2Name);
                
                
                j1StartMatch();
                j2StartMatch();
                
                EPiece j1BoardInit[4][10];
                EPiece j2BoardInit[4][10];
                // Tirage au sort couleur 
                        EColor color = GetRandomColor();
                j1StartGame(color,j1BoardInit);                 
                j2StartGame(abs(color-1),j2BoardInit);         //couleur opposée à celle choisie
                
                //Initialisation des pions sur le plateau
                InitBlueBoard(gameState,j1BoardInit);
                InitRedBoard(gameState,j2BoardInit);
                
                PrintBoard(gameState);
                
                
                
                
                
                

                        //*****// à faire pour chaque jeu
                        //EPiece boardInit[4][10];
                        //j1StartGame(ECred,boardInit);
                        //...
                                //*****// pour chaque joueur, tant que ce n'est pas fini ; ne pas oublier de dupliquer gameState
                                //move=j1NextMove(&gameState);
                                // ...

                                //*****// si attaque, il faut signaler les données à tous les joueurs
                                //SPos p1,p2;
                                //j1AttackResult(p1,EPmarshal,p2,EPbomb);
        //			j2AttackResult(p2,EPbomb,p1,EPmarshal);
                                // ...

        //		j1EndGame();

        //	j1EndMatch();

                return(0);
        }

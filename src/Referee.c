#include "Referee.h"

int Finished(const SGameState * const game)
{
    
    printf("Finished\n");
    return 0;
}

int CorrectMove(const SGameState * const game,SMove move)
{
    printf("CorrectMove\n");
    return 1;
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
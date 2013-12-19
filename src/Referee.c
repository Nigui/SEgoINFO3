#include "Referee.h"

int Finished(const SGameState * const game)
{
    if( game ){
        printf("Finished\n");
    }
    return 0;
}

int CorrectMove(const SGameState * const game,SMove move)
{
    if( game ){
        printf("CorrectMove\n");
    }
    return 1;
}
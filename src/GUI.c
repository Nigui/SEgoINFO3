#include "GUI.h"

void j1InitPlayer_GUI(char name[50])
{
    if( name ){ 
        printf("GUI : j1 InitPlayer\n");
    }
}

void j1StartMatch_GUI()
{
    printf("GUI : j1 StartMatch\n");
}

void j1StartGame_GUI(const EColor color,EPiece boardInit[4][10])
{
    if( color>1 && color<=3 && boardInit ){
        printf("GUI : j1 StartGame\n");
    }
}

void j1EndGame_GUI()
{
    printf("GUI : j1 EndGame\n");
}

void j1EndMatch_GUI()
{
    printf("GUI : j1 EndMatch\n");
}

SMove j1NextMove_GUI(const SGameState * const gameState)
{
    if( gameState ){
        printf("GUI : j1 NextMove\n");
    }
    SMove move;
    return move;
}

void j1AttackResult_GUI(SPos armyPos,EPiece armyPiece,SPos enemyPos,EPiece enemyPiece)
{
     if( armyPiece>=0 && armyPiece<12 && enemyPiece>=0 && enemyPiece<12 ){
        printf("GUI : j1 AttackResult\n");
     }
}

void j1Penalty_GUI()
{
    printf("GUI : j1 Penalty\n");
}



void j2InitPlayer_GUI(char name[50])
{
    if( name ){
        printf("GUI : j2 InitPlayer\n");
    }
}

void j2StartMatch_GUI()
{
    printf("GUI : j2 StartMatch\n");
}

void j2StartGame_GUI(const EColor color,EPiece boardInit[4][10])
{
    if( color>1 && color<=3 && boardInit ){
         printf("GUI : j2 StartGame\n");
    }
}

void j2EndGame_GUI()
{
    printf("GUI : j2 EndGame\n");
}

void j2EndMatch_GUI()
{
    printf("GUI : j2 EndMatch\n");
}

SMove j2NextMove_GUI(const SGameState * const gameState)
{
    if( gameState ){
        printf("GUI : j2 NextMove\n");
    }
    SMove move;
    return move;
}

void j2AttackResult_GUI(SPos armyPos,EPiece armyPiece,SPos enemyPos,EPiece enemyPiece)
{
     if( armyPiece>=0 && armyPiece<12 && enemyPiece>=0 && enemyPiece<12 ){
        printf("GUI : j2 AttackResult\n");
     }
}

void j2Penalty_GUI()
{
    printf("GUI : j2 Penalty\n");
}


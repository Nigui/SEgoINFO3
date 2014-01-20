/* 
 * File:   lowStrategy.h
 * Author: N.G - LG.T - B.F - G.J
 *
 * Created on December 12, 2013, 5:48 PM
 * Command : 
 *              gcc -fPIC -c ../src/*.c ../src/*.h
 *              gcc -shared -o ./lowStrategie/bin/lowStrategy.so.1 lowStrategie/bin/lowStrategy.o
 */

#ifndef LOWSTRATEGY_H
#define	LOWSTRATEGY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../../SEgoINFO3/src/stratego.h"         //TODO à modifier

//Structure Coup + valeur
typedef struct 
{
    SMove move;
    int val;
    
} MoveAvailable;

typedef struct
{
    SMove move;
    EPiece piece;
    EColor color;
} MouvementDetail;

void InitLibrary(char name[50]);
void StartMatch();
void StartGame(const EColor color,EPiece boardInit[4][10]);
void EndGame();
void EndMatch();
SMove NextMove(const SGameState * const gameState);
void AttackResult(SPos armyPos,EPiece armyPiece,SPos enemyPos,EPiece enemyPiece);
void Penalty();

void CpyBoard(const SGameState * const game,SGameState *cpy);
void ExecuteMove(SGameState *game,SMove *move);
int CompareMoves(SMove *move1,SMove *move2);

void ListAvailableMoves();
int ChoseBestMove();
int ValidMove(SMove testingMove); 
int ValidScoutMove(int startL,int startC,int endL,int endC );
int EstimateValMove(SMove move);


#endif	/* LOWSTRATEGY_H */


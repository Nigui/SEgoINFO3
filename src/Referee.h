/* 
 * File:   Referee.h
 * Author: parallels
 *
 * Created on December 17, 2013, 11:24 AM
 */

#ifndef REFEREE_H
#define	REFEREE_H
#include <stdio.h>
#include <stdlib.h>
#include "stratego.h"

typedef struct
{
  	SMove move;
	EPiece piece;
	EColor color;
} MouvementDetail;

//Indique si la manche est terminée
int Finished(const SGameState * const);

/* Indique si le mouvement move est possible
 * 1 si mouvement correcte avec attaque
 * -1 si mouvement correcte sans attaque
 * 0 si mouvement incorrecte
 */ 
int CorrectMove(const SGameState * const game,SMove move,EColor player);
int ValidScoutMove(const SGameState * const,int startL,int startC,int endL,int endC );

void InitList(MouvementDetail *listRepeatedMouv);
int CompareMoves(MouvementDetail *mvtD1, MouvementDetail *mvtD2);
int TestMove(SGameState *currentGame, SMove testingMove);

int InitBlueBoard(SGameState *game,EPiece boardInit[4][10]);
int InitRedBoard(SGameState *game,EPiece boardInit[4][10]);

#endif	/* REFEREE_H */


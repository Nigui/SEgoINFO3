/* 
 * File:   Referee.h
 * Author: parallels
 *
 * Created on December 17, 2013, 11:24 AM
 */

#ifndef REFEREE_H
#define	REFEREE_H
#include <stdio.h>
#include "stratego.h"

//Indique si la manche est terminée
int Finished(const SGameState * const);

/* Indique si le mouvement move est possible
 * 1 si mouvement correcte avec attaque
 * -1 si mouvement correcte sans attaque
 * 0 si mouvement incorrecte
 */ 
int CorrectMove(const SGameState * const,SMove move);

int InitBlueBoard(SGameState *game,EPiece boardInit[4][10]);
int InitRedBoard(SGameState *game,EPiece boardInit[4][10]);

#endif	/* REFEREE_H */


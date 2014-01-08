/* 
 * File:   GUI.h
 * Author: parallels
 *
 * Created on December 19, 2013, 1:17 PM
 */

#ifndef GUI_H
#define	GUI_H

#include <stdio.h>
#include <stdlib.h>
#include "stratego.h"

void j1InitPlayer_GUI(char name[50]);
void j1StartMatch_GUI();
void j1StartGame_GUI(const EColor color,EPiece boardInit[4][10]);
void j1EndGame_GUI();
void j1EndMatch_GUI();
SMove j1NextMove_GUI(const SGameState * const gameState);
void j1AttackResult_GUI(SPos armyPos,EPiece armyPiece,SPos enemyPos,EPiece enemyPiece);
void j1Penalty_GUI();


void j2InitPlayer_GUI(char name[50]);
void j2StartMatch_GUI();
void j2StartGame_GUI(const EColor color,EPiece boardInit[4][10]);
void j2EndGame_GUI();
void j2EndMatch_GUI();
SMove j2NextMove_GUI(const SGameState * const gameState);
void j2AttackResult_GUI(SPos armyPos,EPiece armyPiece,SPos enemyPos,EPiece enemyPiece);
void j2Penalty_GUI();

void Menu(int *maxCp,char* pathIA1,char* pathIA2);

#endif	/* GUI_H */


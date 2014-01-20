/* 
 * File:   OutWriter.h
 * Author: parallels
 *
 * Created on January 13, 2014, 7:28 PM
 */

#ifndef OUTWRITER_H
#define	OUTWRITER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stratego.h"

FILE* strategoLogFile;

int InitLogFile();

int PrintDLine();
int PrintTLine();
int PrintLine();
int PrintStateLine();

int PrintHeaderMatch();
int PrintPhysicalPlayers(char name1[50],char name2[50]);
int PrintIAPlayers(char name1[300],char name2[300]);
int PrintMaxCps(int maxCps);
int PrintLibInitHeader();
int PrintLibrariesInitialisation(char message[300]);

int PrintMatch(int nb);
int PrintColors(char red[300],char blue[300]);
int PrintBoardInitError(int color);
int PrintGameState(const SGameState * const state);
int PrintMove(int color,SMove move);
int PrintInvalidMove(int color,int nbColorPenalties);
int PrintAttackResult(EColor attackColor,SPos attackerPos,EPiece attackerPiece,SPos victimPos,EPiece victimPiece);


int PrintPenalty(char name[300],int color);
int PrintMaxMoveReached();
int PrintMatchWinner(char name[300],int color,int game);

int PrintGameWinner(char name[300],int color);

int CloseLogFile(); 


#endif	/* OUTWRITER_H */


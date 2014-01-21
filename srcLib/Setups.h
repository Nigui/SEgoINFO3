/* 
 * File:   Setups.h
 * Author: parallels
 *
 * Created on December 15, 2013, 4:31 PM
 */

#ifndef SETUPS_H
#define	SETUPS_H

#include "./lowStrategy.h"
#include <math.h>

void SetupPieces(int nb,EPiece boardInit[4][10]);
/*
 * This is one of his most “famous” setups, which is a dubious quality for a 
 * Stratego setup. He didn't used any other setup as often on tournaments and 
 * several other players have successfully used this setup as well. 
 * It is a bit predictable, but all pieces are at hand when you need them 
 * and it works well for both attack and defense.
 */
void Setup1(EPiece boardInit[4][10]);
/*
 * This is another setup he has used often on tournaments. 
 * It’s outspoken aggressive and not very suitable for careful slow games, 
 * but it’s less predictable and works better against stronger players.
 */
void Setup2(EPiece boardInit[4][10]);
/*
 * Another setup he used often. Harder It’s harder to defend the flag in 
 * the corner, but otherwise works very well.
 */
void Setup3(EPiece boardInit[4][10]);
/*
 * It's a good all-round setup.
 */
void Setup4(EPiece boardInit[4][10]);
/*
 * The flag on this position is something he often used against 
 * stronger opponents, but the rest of the pieces he usually change 
 * every time in such games.
 */
void Setup5(EPiece boardInit[4][10]);
/*
 * This is an old setup that he invented on his first world championships. 
 * It’s rather weak defensively though, it worked well when setups of 
 * this style were still unexpected but later it got too weak.
 */
void Setup6(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                              Cyclone Defence : 
 ************************************************************************
 * A conventional alignment, the Cyclone Defense holds Scouts in reserve, 
 * and places Miners in position for an early foray against enemy mines. 
 * The Flag is encased in a Bomb Shield, while the remaining explosives 
 * lurk in the front lines.
 */
void Setup7(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                             The Tempest Defense : 
 ************************************************************************
 * Deceit is the key to the Tempest Defense. High-ranking soldiers and 
 * eager Scouts dot the front lines; the Marshal and one Colonel form a 
 * mini-strike force. One layer of Bombs and another of ranked pieces 
 * enclose your Flag.
 */
void Setup8(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                              Triple Threat : 
 ************************************************************************
 * High-ranking units and a deployment of Scouts fill the front lines, 
 * while Miners are held in reserve. A formidable array of Bombs clots 
 * the back row, where your side's standard also dwells.
 */
void Setup9(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                              Scout's Gambit : 
 ************************************************************************
 * Several Scouts share the front lines with your army's top officers. 
 * Bombs are scattered randomly through your defenses, posing a deadly 
 * challenge to reckless intruders.
 */
void Setup10(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                              On Guard! : 
 ************************************************************************
 * Jagged Bomb placement is sure to cause the enemy discomfort. 
 * Potent pieces hover on the Flag's flanks. Captains and Majors 
 * in the forward ranks are poised for action.
 */
void Setup11(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                             Shoreline Bluff : 
 ************************************************************************
 * Defensive deception is displayed in forward Flag placement. A Bomb 
 * occupies each flank, while the remaining Bombs are scattered throughout 
 * the lines. Several high-ranking troops are stationed near the Flag, 
 * offering further protection. Reserve Scouts are posted to the rear.
 */
void Setup12(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                             Corner Fortress : 
 ************************************************************************
 * A diagonal line of Bombs and nestled Sergeants shields your 
 * Flag in once corner. Scouts deploy in the front ranks, along 
 * with a group of high officers on battle alert.
 */
void Setup13(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                             Shield Defense : 
 ************************************************************************
 * Your Flag is wrapped in a Bomb shield in the center of your defenses. 
 * The Marshal, General and a sprinkling of Scouts occupy forward positions, 
 * while Colonels and Majors lurk just behind. A corps of Miners is in reserve.
 */
void Setup14(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                             Corner Blitz : 
 ************************************************************************
 * A formation of high officers prepares for the attack on lake's edge, 
 * while a cluster of Miners waits for the call. A smattering of Bombs 
 * turns your rear ranks into a most deadly destination.
 */
void Setup15(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                             Wheel of Danger : 
 ************************************************************************
 * An odd combination of Scouts and Bombs populate the forward lines. 
 * A number of high officers wait in reserve, while the Flag is encapsulated 
 * in a Bomb rectangle.
 */
void Setup16(EPiece boardInit[4][10]);/*
 ************************************************************************
 *                             Blitzkrieg! : 
 ************************************************************************
 * Your most powerful pieces assemble in the first row; several Miners 
 * join the forward deployment. Well-dispersed Bombs are a smoking 
 * black invitation to an an opponent's recklessness.
 */
void Setup17(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                             Early Warning! : 
 ************************************************************************
 * While five of six Bombs are grouped around your standard, Scouts and 
 * top officers ready for the attack. Miners are poised to one side, and 
 * Captains and Lieutenants populate the rear.
 */
void Setup18(EPiece boardInit[4][10]);
/*
 ************************************************************************
 *                             Man the Barricades : 
 ************************************************************************
 * Pairs of Bombs nestle in the front lines, while your Marshal guards the 
 * Flag in one corner. Woe betide the aggressive foe! High officers make up 
 * the forward alignment; Miners and Scouts bide their time in reserve until 
 * the call for duty sounds.
 */
void Setup19(EPiece boardInit[4][10]);




#endif	/* SETUPS_H */


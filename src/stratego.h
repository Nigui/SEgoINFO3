#ifndef _STRATEGO_H
	#define _STRATEGO_H

//Command : gcc -Wall SEgoINFO3/src/stratego.* -o SEgoINFO3/bin/stratego -ldl -lm

/////////// Strutures � utiliser

// Etat d'une case du jeu
typedef enum
{
	ECnone,                 // val : 0
	EClake,                 // val : 1
	ECred,                  // val : 2
	ECblue                  // val : 3
} EColor;

//Liste de type de pion
typedef enum
{
	EPbomb=0,               // nb : 6 -- val : 0
	EPspy,                  // nb : 1 -- val : 1
	EPscout,                // nb : 8 -- val : 2
	EPminer,                // nb : 5 -- val : 3
	EPsergeant,             // nb : 4 -- val : 4
	EPlieutenant,           // nb : 4 -- val : 5
	EPcaptain,              // nb : 4 -- val : 6
	EPmajor,                // nb : 3 -- val : 7
	EPcolonel,              // nb : 2 -- val : 8
	EPgeneral,              // nb : 1 -- val : 9
	EPmarshal,              // nb : 1 -- val : 10
	EPflag,                 // nb : 1 -- val : 11
	EPnone,                 // nb : ? -- val : 12
} EPiece;


typedef struct
{
	EColor content;
	EPiece piece;
} SBox;


// Structure de repr�sentation du jeu avec son plateau
typedef struct
{
	SBox board[10][10];	// Tableau du jeu de 10 cases par 10. dim1=ligne dim2=colonne
	unsigned int redOut[11];	// Tableau de comptage des pi�ces rouges �limin�es (index�es par la valeur de EPiece : EPbomb=0, ..., EPmarshal=10
	unsigned int blueOut[11];	// Tableau de comptage des pi�ces bleues �limin�es (index�es par la valeur de EPiece : EPbomb=0, ..., EPmarshal=11
} SGameState;

// Structure de repr�sentation d'une position
typedef struct
{
	int line;
	int col;
} SPos;

// Structure de représentation d'un mouvement
typedef struct
{
	SPos start;
	SPos end;
} SMove;

/////////// Fonctions à utiliser
// Les prototypes en commentaires sont à implémenter dans la librairie
// Les types pointeur de fonction dans l'application

/**
 * Initialiser la librairie
 * @param char name[50]
 *	nom associé à la librairie
 */
//void InitLibrary(char name[50]);
typedef void (*pfInitLibrary)(char[50]);

/**
 * Initialiser l'IA pour un match
 */
//void StartMatch();
typedef void (*pfStartMatch)();

/**
 * Initialiser l'IA pour une manche (d'un match)
 * @param const EColor color
 *	couleur du joueur
 * @param EPiece boardInit[4][10]
 *	variable en sortie : initialisation du jeu pour un joueur (ligne 0 = ligne la plus proche du joueur)
 */
//void StartGame(const EColor color,EPiece boardInit[4][10]);
typedef void (*pfStartGame)(const EColor,EPiece[4][10]);

/**
 * Fin d'une manche (d'un match)
 */
//void EndGame();
typedef void (*pfEndGame)();

/**
 * Fin d'un match
 */
//void EndMatch();
typedef void (*pfEndMatch)();

/**
 * Prise de d�cision de la part de l'IA
 * @param const SGameState * const gameState
 *	l'�tat du jeu courant
 * @return SMove
 *	mouvement � effectuer par l'IA
 */
//SMove NextMove(const SGameState * const gameState);
typedef SMove (*pfNextMove)(const SGameState * const);

/**
 * Indication du r�sultat d'une attaque (r�sultat envoy� � tous les joueurs)
 * @param SPos armyPos
 *	position de l'�l�ment de l'arm�e du joueur (attaquant ou attaqu�e)
 * @param EPiece armyPiece
 *	type de de l'�l�ment de l'arm�e du joueur (attaquant ou attaqu�e)
 * @param SPos enemyPos
 *	position de l'�l�ment de l'ennemi (attaquant ou attaqu�e)
 * @param EPiece enemyPiece
 *	type de de l'�l�ment de l'ennemi (attaquant ou attaqu�e)
 */
//void AttackResult(SPos armyPos,EPiece armyPiece,SPos enemyPos,EPiece enemyPiece);
typedef void (*pfAttackResult)(SPos,EPiece,SPos,EPiece);

/**
 * Indication d'une p�nalit�e pour r�gle non respect�e -> coup pr�c�dent annul�
 */
//void Penalty();
typedef void (*pfPenalty)();


#endif

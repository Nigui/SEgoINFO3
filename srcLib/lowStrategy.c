#include "lowStrategy.h"
#include "Setups.h"


int color;
int enemyColor;

MoveAvailable listAvailableMoves[100];
int cptAvailableMoves = 0;

SGameState *currentGame;

MouvementDetail listRepeatedMouv[3];
int repeatedMouv = 0;

SPos lastEnemyAttackPos;
EPiece lastEnemyAttackPiece;

void InitLibrary(char name[50]) {
    printf("InitLibrary\n");
    strcpy(name, "Henry");
}

void StartMatch() {
    printf("StartMatch %d\n",color);
}

void StartGame(const EColor aColor, EPiece boardInit[4][10]) {
    printf("StartGame %d\n",aColor);
    if (aColor > 1 && aColor <= 3) {
        
        //Initialisation de la couleur de l'IA
        color = aColor;
        
        if( color == 2 ){ enemyColor = 3;}
        else { enemyColor = 2;}
        
        //On alloue la mémoire des plateaux de test de l'IA
        currentGame = (SGameState*) malloc(sizeof(SGameState));
        
        lastEnemyAttackPiece = -1;
        lastEnemyAttackPos.line = -1;
        lastEnemyAttackPos.col = -1;
        
        //Choix d'une méthode de placement au hasard
        //TODO, ajouter la méthode utilisée à la liste des méthodes utilisée
        int N = 1;
        int M = 19;
        int numSetup = (int) N + (rand() % (int) (M - N + 1));
        printf("--Setup n°%d--\n",numSetup);
        SetupPieces(numSetup,boardInit);
    }
}

void EndGame() {
    printf("EndGame\n");
    free(currentGame);
}

void EndMatch() {
    printf("EndMatch\n");
}

SMove NextMove(const SGameState * const gameState) {
    
    SMove ret;
    
    //On recopie le plateau courant
    CpyBoard(gameState,currentGame);
    
    //On dévoile la valeur du pion ennemi gagnant de la dernière attaque
    if( lastEnemyAttackPiece != -1 && lastEnemyAttackPos.line != -1 && lastEnemyAttackPos.col != -1 ){
        currentGame->board[lastEnemyAttackPos.line][lastEnemyAttackPos.col].piece = lastEnemyAttackPiece;
        lastEnemyAttackPiece = -1 ;
        lastEnemyAttackPos.line = -1 ;
        lastEnemyAttackPos.col = -1 ;
    }
        
    ListAvailableMoves();
    
    int indexBestMove = ChoseBestMove();
    if( indexBestMove == -1 ){
        ret.start.line = -1;
        ret.start.col = -1;
        ret.end.line = -1;
        ret.end.col = -1;
    }
    else{
        ret = listAvailableMoves[indexBestMove].move;
    }
    
    //On ajoute le mouvement au mouvements répétés
    MouvementDetail mvtD;
    mvtD.color = color;
    mvtD.move = ret;
    mvtD.piece = currentGame->board[ret.start.line][ret.start.col].piece;
            
    switch (repeatedMouv)
    {
        case 0: 
                listRepeatedMouv[repeatedMouv] = mvtD;
                repeatedMouv++;
                break;
        case 1:
                if( mvtD.piece == listRepeatedMouv[0].piece ){
                    listRepeatedMouv[repeatedMouv] = mvtD;
                    repeatedMouv++;
                }
                else{ repeatedMouv = 0; }
                break;
        case 2:
            if( (mvtD.piece == listRepeatedMouv[0].piece) && (CompareMoves(&mvtD.move,&listRepeatedMouv[0].move)==1) ){
                listRepeatedMouv[repeatedMouv] = mvtD;
                repeatedMouv++;
            }
            else{ repeatedMouv = 0; }
            break;
        default:
            repeatedMouv = 0;
            break;
    }
    
    //On exécute le mouvement sur notre plateau courant
    ExecuteMove(currentGame,&ret);
    
    return ret;
}

void AttackResult(SPos armyPos, EPiece armyPiece, SPos enemyPos, EPiece enemyPiece) {
    if (armyPiece >= 0 && armyPiece < 12 && enemyPiece >= 0 && enemyPiece < 12) {
        //Si l'ennemi a battu notre piece on connait sa valeur
        if( enemyPiece > armyPiece ){
            if( color == ECred ){
                enemyPos.line = 9-enemyPos.line;
            }
            lastEnemyAttackPiece = enemyPiece;
            lastEnemyAttackPos = enemyPos;
        }
    }
}

void Penalty() {
    printf("Penalty\n");
}

void ListAvailableMoves()
{
    //Mise à 0 du nombre de mouvements disponibles
    cptAvailableMoves = 0;
    
    int i,j,k;
    
    /* On recherche parmis toutes les cases du plateau, celles disponibles */
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            SBox current = currentGame->board[i][j];
            //Si case contient une pièce qui est de la couleur de l'IA
            if( current.piece != EPnone && current.content == color ){
                //On teste toutes les cases ou l'on peut se déplacer
                SBox nextBox;
                for( k=0;k<4;k++ ){    
                    int endL;
                    int endC;
                    switch(k)
                    {
                        case 0:
                            if( i==0 ){ continue; } //Si le pion ne peut reculer
                            endL = i-1;
                            endC = j;
                            break;
                        case 1:
                            if( j==0 ){ continue; } //Si le pion ne peut se déplacer à gauche
                            endL = i;
                            endC = j-1;
                            break;
                        case 2:
                            if( i==9 ){ continue; } //Si le pion ne peut avancer
                            endL = i+1;
                            endC = j;
                            break;
                        case 3:
                            if( j==9 ){ continue; } //Si le pion ne peut se déplacer à droite
                            endL = i;
                            endC = j+1;
                            break;
                    }  
                    nextBox = currentGame->board[endL][endC];
                    
                    MoveAvailable moveAvailable;
                    SMove move;
                    move.start.line = i;
                    move.start.col = j;
                    move.end.line = endL;
                    move.end.col = endC;

                    moveAvailable.move = move;
                        
                    //On vérifie que le coup est valide
                    if( ValidMove(move) ){
                        
                        //Si la case est vide on l'ajoute a la liste des mouvements disponibles
                        if( nextBox.piece == EPnone ){
                            moveAvailable.val = 0;
                        }
                        else{
                            moveAvailable.val = EstimateValMove(move);
                        }
                        listAvailableMoves[cptAvailableMoves] = moveAvailable;
                        cptAvailableMoves++;
                    }
                    
               }
           }
        }
    }
}

int ChoseBestMove()
{
    if( cptAvailableMoves == 0 ){ return -1; }
    
    int ret,i,score = -1000;
    
    for(i=0;i<cptAvailableMoves;i++){
        if( listAvailableMoves[i].val > score)
        {
            score = listAvailableMoves[i].val;
            ret = i;
        }
        else if( listAvailableMoves[i].val == score ){
            int selected = rand()%2;
            if( selected == 0 ){
                score = listAvailableMoves[i].val;
                ret = i;
            }
        }
    }
    return ret;
}

int ValidMove(SMove testingMove)
{   
    //Si le mouvement prend effet dans les bornes de la grille
    if( testingMove.end.line<0 || testingMove.end.line>9 ||
        testingMove.end.col<0 || testingMove.end.col>9 ){ return 0; }
    
    //Si la case de départ est occupée par l'ennemie
    if( currentGame->board[testingMove.start.line][testingMove.start.col].content != color ){ return 0; }
    
    //Si la case d'arrivée est un lac ou appartient à l'IA
    if( currentGame->board[testingMove.end.line][testingMove.end.col].content == EClake || 
        currentGame->board[testingMove.end.line][testingMove.end.col].content == color) { return 0; }
        
    //Si la pièce de départ ne peut bouger
    switch( currentGame->board[testingMove.start.line][testingMove.start.col].piece )
    {
        case EPbomb:
            return 0;
        case EPflag:
            return 0;
    }
    
    //Vérification de la règle VA ET VIENT
    MouvementDetail mvtD;
    mvtD.color = color;
    mvtD.move = testingMove;
    mvtD.piece = currentGame->board[testingMove.start.line][testingMove.start.col].piece;
    //Si le nombre de coup répétés est critique et que c'est la même pièce que la dernière déplacée et qu'il s'agit d'un mouvement déjà effectué
    if( repeatedMouv == 3 && (mvtD.piece == listRepeatedMouv[2].piece) && (CompareMoves(&mvtD.move,&listRepeatedMouv[1].move)==1) ){
        repeatedMouv = 0;
        return 0;
    }
    
    //Si l'on se déplace vers la gauche ou la droite
    if( testingMove.start.line == testingMove.end.line ){
        //Si le déplacement est d'une seule case alors coup valide
        if( abs(testingMove.start.col - testingMove.end.col)==1){
            return 1;
        }
    }
    //Si l'on se déplace en avant ou en arrière
    if( testingMove.start.col == testingMove.end.col ){
        //Si l'on se déplace d'une seule case alors le coup est valide
        if( abs(testingMove.start.line - testingMove.end.line)==1){
            return 1;
        }
    }
    
    //Si la pièce jouée est un éclaireur
    if( currentGame->board[testingMove.start.line][testingMove.start.col].piece == EPscout ){
        //On vérifie que l'éclaireur effectue un coup valide sur plusieurs cases
        return ValidScoutMove(testingMove.start.line,testingMove.start.col,testingMove.end.line,testingMove.end.col);
    }
 
    return 0;
    
}

int ValidScoutMove(int startL,int startC,int endL,int endC )
{
    //Si l'on se déplace vers la gauche ou la droite
    if( startL == endL ){
        //Si l'éclaireur se déplace d'une seule case
        if( abs(startC - endC ) == 1 ){
            return 1;
        }
        //Sinon on vérifie pour chaques cases du déplacement, qu'elles sont conjointes
        if( (startC - endC) > 0 ){ return ValidScoutMove(startL,startC-1,endL,endC); }
        if( (startC - endC) < 0 ){ return ValidScoutMove(startL,startC+1,endL,endC); }
    }
    //Si l'on se déplace du haut vers le bas
    else if( startC == endC ){
        //Si l'éclaireur se déplace d'une seule case
        if( abs(startL - endL) == 1 ){
            return 1;
        }
        //Sinon on vérifie pour chaques cases du déplacement, qu'elles sont conjointes
        if( (startL - endL) > 0 ){ return ValidScoutMove(startL-1,startC,endL,endC); }
        if( (startL - endL) < 0 ){ return ValidScoutMove(startL+1,startC,endL,endC); }
    }
    return 0;
}

int EstimateValMove(SMove move)
{
    SBox startBox = currentGame->board[move.start.line][move.start.col];
    SBox enemyBox = currentGame->board[move.end.line][move.end.col];
    
    /* 
     * Si l'ennemi est connu 
     */
    if(enemyBox.content == enemyColor && enemyBox.piece != ECnone ){
        //On traite les cas particuliers des pions
                //Pion face au drapeau
                if( enemyBox.piece == EPflag ){ return 1000; }
                
                //Marshall face à un espion
                if( enemyBox.piece == EPspy && startBox.piece == EPmarshal ){ return 800; }
                
                //Espion contre Marshall
                if( enemyBox.piece == EPmarshal && startBox.piece == EPspy ){ return 800; }
                
                //Espion contre autre pion
                if( startBox.piece == EPspy && enemyBox.piece > EPspy && enemyBox.piece <= EPmarshal ){ return -500+(enemyBox.piece); }
                
                //Démineur face bombe
                if( startBox.piece == EPminer && enemyBox.piece == EPbomb ){ return 11; }
                
                //Pion face bombe sauf démineur
                if( startBox.piece >= EPspy && startBox.piece <= EPmarshal && enemyBox.piece == EPbomb ){ return -500; }
        
        //Si l'ennemie est égal ou supérieur à notre pion
        if( enemyBox.piece >= startBox.piece ){ return -(startBox.piece)*10 ;}

        else{ return -(enemyBox.piece)*10 ;}
    }
    
    /*
     * Sinon TODO Développer stratégie
     */
    return 0;
}

void CpyBoard(const SGameState * const game,SGameState *cpy)
{
    int i,j;
    for(i=0;i<11;i++){
        cpy->blueOut[i] = game->blueOut[i];
        cpy->redOut[i] = game->redOut[i];
    }

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            cpy->board[i][j].content = game->board[i][j].content;
            cpy->board[i][j].piece = game->board[i][j].piece;
        }
    }
}

void ExecuteMove(SGameState *game,SMove *move)
{ 
    SBox *start = &game->board[move->start.line][move->start.col];
    SBox *end = &game->board[move->end.line][move->end.col];
    
    //Si attaque
    if( end->content == enemyColor ){
        if( start->piece > end->piece ){
            if( end->content == ECblue ){ game->blueOut[end->content]++; }
            else{ game->redOut[end->content]++; }
            end->content = start->content;
            end->piece = start->piece;
        }
        else if( start->piece < end->piece ){
            if( start->content == ECblue ){ game->blueOut[start->content]++; }
            else{ game->redOut[start->content]++; }
        }
        else{
            if( start->content == ECblue ){ 
                game->blueOut[start->content]++;
                game->redOut[end->content]++; 
            }
            else{ 
                game->blueOut[end->content]++;
                game->redOut[start->content]++; 
            }
            end->content = ECnone;
            end->piece = EPnone;
        }
    }
    else{
        end->content = start->content;
        end->piece = start->piece;
    }
    
    start->content = ECnone;
    start->piece = EPnone;
}

int CompareMoves(SMove *move1,SMove *move2)
{
    if( move1->start.line == move2->start.line){
        if( move1->start.col == move2->start.col){
            if( move1->end.line == move2->end.line){
                if( move1->end.col == move2->end.col){
                    return 1;
                }
            }
        }
    }
    return 0;
}
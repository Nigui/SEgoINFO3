#include "Referee.h"

int Finished(const SGameState * const game)
{
    if( game->blueOut[EPspy] == 1 ){
        if( game->blueOut[EPscout] == 8 ){
            if( game->blueOut[EPminer] == 5 ){
                if( game->blueOut[EPsergeant] == 4 ){
                    if( game->blueOut[EPlieutenant] == 4 ){
                        if( game->blueOut[EPcaptain] == 4 ){
                            if( game->blueOut[EPmajor] == 3 ){
                                if( game->blueOut[EPcolonel] == 2 ){
                                    if( game->blueOut[EPgeneral] == 1 ){
                                        if( game->blueOut[EPmarshal] == 1 ){
                                            printf(" plus de bleus\n");
                                            return 2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
                                            
    
    if( game->redOut[EPspy] == 1 ){
        if( game->redOut[EPscout] == 8 ){
            if( game->redOut[EPminer] == 5 ){
                if( game->redOut[EPsergeant] == 4 ){
                    if( game->redOut[EPlieutenant] == 4 ){
                        if( game->redOut[EPcaptain] == 4 ){
                            if( game->redOut[EPmajor] == 3 ){
                                if( game->redOut[EPcolonel] == 2 ){
                                    if( game->redOut[EPgeneral] == 1 ){
                                        if( game->redOut[EPmarshal] == 1 ){
                                            printf(" plus de rouges\n");
                                            return 3;
                                            }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
                                    
    int i,j,nbBlueMovable = 0,nbRedMovable = 0;
    for( i=0;i<10;i++){
        for(j=0;j<10;j++){
            //On regarde les pièces qui peuvent bouger
            if( (game->board[i][j].piece > 0) && (game->board[i][j].piece < 11) ){
                //Si bord du plateau gauche ou bombe à gauche ou drapeau à gauche
                if( (j==0) || (game->board[i][j-1].piece == EPbomb) || (game->board[i][j-1].piece == EPflag) ){
                    //Si bord droit ou bombe droite ou drapeau droite
                    if( (j==9) || (game->board[i][j+1].piece == EPbomb) || (game->board[i][j+1].piece == EPflag) ){
                        //Si bord du plateau haut ou bombe dessus ou drapeau dessus
                        if( (i==0) || (game->board[i-1][j].piece == EPbomb) || (game->board[i-1][j].piece == EPflag) ){
                            //Si bord bas ou bombe bas ou drapeau bas
                            if( (i==9) || (game->board[i+1][j].piece == EPbomb) || (game->board[i+1][j].piece == EPflag) ){
                                continue;
                            }
                            else{ 
                                if( game->board[i][j].content == ECred ){ nbRedMovable++; }
                                else{ nbBlueMovable++; }
                            }
                        }
                        else{ 
                            if( game->board[i][j].content == ECred ){ nbRedMovable++; }
                            else{ nbBlueMovable++; }
                        }
                    }
                    else{ 
                        if( game->board[i][j].content == ECred ){ nbRedMovable++; }
                        else{ nbBlueMovable++; }
                    }
                }
                else{ 
                    if( game->board[i][j].content == ECred ){ nbRedMovable++; }
                    else{ nbBlueMovable++; }
                }
            }
        }
    }
    if( nbBlueMovable == 0 ){ printf("les bleus sont bloqués\n");return 2; }
    else{ 
        if( nbRedMovable == 0 ){ printf("les rouges sont bloqués\n");return 3; }
    }
    
    int blueFlag = 0;
    int redFlag = 0;
    
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if( game->board[i][j].piece == EPflag ){ 
                if( game->board[i][j].content == ECblue ){ blueFlag++; }
                else{ redFlag++; }
            }
        }
    }
    
    if( blueFlag == 0 && redFlag == 1 ){ printf("drapeau bleu capturé\n");return 2; }
    else if( blueFlag == 1 && redFlag == 0 ){ printf("drapeau rouge capturé\n");return 3; }
    
    return 0;
}

int CorrectMove(const SGameState * const game,SMove move,EColor player)
{                   
    //Si le mouvement prend effet dans les bornes de la grille
    if( move.end.line<0 || move.end.line>9 ||
        move.end.col<0 || move.end.col>9 ){ return 0; }

    //Si la case de départ est occupée par l'ennemie
    if( game->board[move.start.line][move.start.col].content != player ){ return 0; }

    //Si la case d'arrivée est un lac ou appartient à l'IA
    if( game->board[move.end.line][move.end.col].content == EClake || 
        game->board[move.end.line][move.end.col].content == player) { return 0; }

    //Si la pièce de départ ne peut bouger
    switch( game->board[move.start.line][move.start.col].piece )
    {
        case EPbomb:
            return 0;
        case EPflag:
            return 0;
        default:
            break;
    }

    //Vérification de la règle VA ET VIENT
    struct MouvementDetail
    {
    	SMove move;
    	EPiece piece;
    	EColor color;
    };

    MouvementDetail listRepeatedBlueMouv[3];
    MouvementDetail listRepeatedRedMouv[3];

    InitList(MouvementDetail *listRepeatedMouv)
    {
        int i;
        for (i = 0; i < 3; ++i)
        {
            listRepeatedMouv[i]=0;
        }
    }
    
    CompareMoves(MouvementDetail *mvtD1, MouvementDetail *mvtD2)
    {
        if(mvtD1->move.start.line == mvtD2->move.start.line 
            && mvtD1->move.start.col == mvtD2->move.start.col 
            && mvtD1->move.end.line == mvtD1->move.end.line 
            && mvtD1->move.end.col == mvtD1->move.end.col)
        {
            if (mvtD1->piece == mvtD2->piece)
            {
                if(mvtD1->color == mvtD2->color)
                {
                    return 1;
                }
            }
        }
        else return 0;
    }

   TestMove(SGameState currentGame, SMove testingMove)
    {
        MouvementDetail mvtD;
        mvtD.color = color;
        mvtD.move = testingMove;
        mvtD.piece = currentGame->board[testingMove.start.line][testingMove.start.col].piece;
        // Si le nombre de coup répétés est critique et que c'est la même pièce que la dernière déplacée et qu'il s'agit d'un mouvement déjà effectué
        if(repeatedMouv == 3 && (mvtD.piece == listRepeatedMouv[2].piece) && (CompareMoves(&mvtD.move, &listRepeatedMouv[1].move) == 1))
        {
            repeatedMouv = 0;
            return 0;
        }
    }

    //Si l'on se déplace vers la gauche ou la droite
    if( move.start.line == move.end.line ){
        //Si le déplacement est d'une seule case alors coup valide
        if( abs(move.start.col - move.end.col)==1){
                if( game->board[move.end.line][move.end.col].piece == EPnone ) { return -1; }
                else{ return 1; }
        }
    }
    //Si l'on se déplace en avant ou en arrière
    if( move.start.col == move.end.col ){
        //Si l'on se déplace d'une seule case alors le coup est valide
        if( abs(move.start.line - move.end.line)==1){
                if( game->board[move.end.line][move.end.col].piece == EPnone ) { return -1; }
                else{ return 1; }
        }
    }

    //Si la pièce jouée est un éclaireur
    if( game->board[move.start.line][move.start.col].piece == EPscout ){
        //On vérifie que l'éclaireur effectue un coup valide sur plusieurs cases
        if( game->board[move.end.line][move.end.col].piece == EPnone ) { return (-1)*ValidScoutMove(game,move.start.line,move.start.col,move.end.line,move.end.col); }
        else{ return ValidScoutMove(game,move.start.line,move.start.col,move.end.line,move.end.col); }
    }

    return 0;
}

int ValidScoutMove(const SGameState * const game,int startL,int startC,int endL,int endC )
{
    if( game->board[startL][startC].content == ECnone && game->board[startL][startC].piece == EPnone ){
        //Si l'on se déplace vers la gauche ou la droite
        if( startL == endL ){
            //Si l'éclaireur se déplace d'une seule case
            if( abs(startC - endC ) == 1 ){
                return 1;
            }
            //Sinon on vérifie pour chaques cases du déplacement, qu'elles sont conjointes
            if( (startC - endC) > 0 ){ return ValidScoutMove(game,startL,startC-1,endL,endC); }
            if( (startC - endC) < 0 ){ return ValidScoutMove(game,startL,startC+1,endL,endC); }
        }
        //Si l'on se déplace du haut vers le bas
        else if( startC == endC ){
            //Si l'éclaireur se déplace d'une seule case
            if( abs(startL - endL) == 1 ){
                return 1;
            }
            //Sinon on vérifie pour chaques cases du déplacement, qu'elles sont conjointes
            if( (startL - endL) > 0 ){ return ValidScoutMove(game,startL-1,startC,endL,endC); }
            if( (startL - endL) < 0 ){ return ValidScoutMove(game,startL+1,startC,endL,endC); }
        }
    }
    return 0;
}

int InitBlueBoard(SGameState *game,EPiece boardInit[4][10])
{
    int listPiece[12] = {6,1,8,5,4,4,4,3,2,1,1,1};
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<10;j++){
            EPiece p = boardInit[i][j];
            if( p<0 || p>12 ){return 0;}
            if( listPiece[p] == 0 ){return 0;}
            else{ listPiece[p]--;}
            game->board[i][j].piece = p;
            game->board[i][j].content = ECblue;
        }
    }
    return 1;
}

int InitRedBoard(SGameState *game,EPiece boardInit[4][10])
{
    int listPiece[12] = {6,1,8,5,4,4,4,3,2,1,1,1};
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<10;j++){
            EPiece p = boardInit[i][j];
            if( p<0 || p>12 ){return 0;}
            if( listPiece[p] == 0 ){return 0;}
            else{ listPiece[p]--;}
            game->board[9-i][j].piece = boardInit[i][j];
            game->board[9-i][j].content = ECred;
        }
    }
    return 1;
}

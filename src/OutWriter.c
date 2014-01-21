#include "OutWriter.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int InitLogFile()
{
    strategoLogFile = fopen("./StrategoLog.txt", "a+t");
    if( strategoLogFile ){ return 1;}
    return 0;
}

int PrintDLine()
{
    if( strategoLogFile ){
        fprintf(strategoLogFile,"###############################################################################################\n");
    }
    else{ return 0; }
    return 1;
}

int PrintTLine()
{
    if( strategoLogFile ){
        fprintf(strategoLogFile,"------------------------------------------------------------------------------------------\n");
    }
    else{ return 0; }
    return 1;
}
int PrintLine()
{
    if( strategoLogFile ){
        fprintf(strategoLogFile,"\t\t______________________________________________________________________________________\n");
    }
    else{ return 0; }
    return 1;
}

int PrintStateLine()
{
    if( strategoLogFile ){
        fprintf(strategoLogFile,"\t\t---------------------------------------------------------------     ------------------\n");
    }
    else{ return 0; }
    return 1;
}

int PrintHeaderMatch()
{
    if( strategoLogFile ){
        time_t timestamp;
        struct tm * t;
        timestamp = time(NULL);
        t = localtime(&timestamp);
        
        PrintDLine();
        fprintf(strategoLogFile,"# Partie du %02u/%02u/%04u -- %02u:%02u\n",t->tm_mday,t->tm_mon+1, 1900 + t->tm_year,t->tm_hour, t->tm_min);
        PrintDLine();
    }
    else{ return 0; }
    return 1;
}

int PrintPhysicalPlayers(char name1[50],char name2[50])
{
    if( strategoLogFile ){
        if( name1 == NULL ){ name1 = ""; }
        if( name2 == NULL){ name2 = ""; }
        fprintf(strategoLogFile,"Joueurs physique : %s , %s\n",name1,name2);
    }
    else{ return 0; }
    return 1;
}
int PrintIAPlayers(char name1[300],char name2[300])
{
    if( strategoLogFile ){
        fprintf(strategoLogFile,"Joueurs IA : %s , %s\n",name1,name2);
    }
    else{ return 0; }
    return 1;    
}

int PrintMaxCps(int maxCps)
{
    if( strategoLogFile ){
        fprintf(strategoLogFile,"Coups Max : %d\n",maxCps);
    }
    else{ return 0; }
    return 1;  
}

int PrintLibInitHeader()
{
    if( strategoLogFile ){
        fprintf(strategoLogFile,"-- Chargement des joueurs\n");
    }
    else{ return 0; }
    return 1;  
}

int PrintLibrariesInitialisation(char message[300])
{
    if( strategoLogFile ){
        fprintf(strategoLogFile,"-- %s",message);
    }
    else{ return 0; }
    return 1; 
}

int PrintMatch(int nb)
{
    if( strategoLogFile ){
        PrintTLine();
        fprintf(strategoLogFile,"-- Match %d\n",nb);
        PrintTLine();
    }
    else{ return 0; }
    return 1; 
}

int PrintColors(char red[300],char blue[300])
{
    if( strategoLogFile ){
        fprintf(strategoLogFile,"\t\tRouge : %s\n",red);
        fprintf(strategoLogFile,"\t\tBleu : %s\n",blue);
    }
    else{ return 0; }
    return 1;
}

int PrintBoardInitError(int color)
{
    if( strategoLogFile ){
        if( color == ECred ){ fprintf(strategoLogFile,"\t\t!!! Erreur initialisation joueur Rouge\n"); }
        else{ fprintf(strategoLogFile,"\t\t!!! Erreur initialisation joueur Bleu\n"); }
    }
    else{ return 0; }
    return 1;
}

int PrintGameState(const SGameState * const state)
{
    if( strategoLogFile ){
        
        fprintf(strategoLogFile,"\n");
        int i,j;
        //affichage nombres colonnes
        fprintf(strategoLogFile,"\t\t  |");
        for(i=0;i<10;i++){
            fprintf(strategoLogFile,"  %d  |",i);
        }
        fprintf(strategoLogFile,"     |");
        fprintf(strategoLogFile,"  Bleu |");
        fprintf(strategoLogFile," Rouge |");
        fprintf(strategoLogFile,"\n");
        PrintStateLine();
        for(i=0;i<10;i++){
            fprintf(strategoLogFile,"\t\t%d |",i);
            for(j=0;j<10;j++){
                int content = state->board[i][j].content;
                int piece = state->board[i][j].piece;
                char sign = 'B';
                if( content == EClake ){sign = 'X';}
                else if(content == ECnone ){sign = ' ';}
                else if(content == ECred ){sign = 'R';}

                if( piece == 12 && content == 1 ){ fprintf(strategoLogFile,"  %c  |",sign); }
                else if( piece == 12 && content == 0){ fprintf(strategoLogFile,"     |"); }
                else if( piece==10 ){ fprintf(strategoLogFile," %c%d |",sign,piece); }
                else if( piece==11 ){ fprintf(strategoLogFile,"  %cF |",sign); }
                else{ fprintf(strategoLogFile,"  %c%d |",sign,piece); }
            }
            fprintf(strategoLogFile,"  %d  |",i);
            if( state->blueOut[i] <10 ){ fprintf(strategoLogFile,"   %d   |",state->blueOut[i]); }
            else{ fprintf(strategoLogFile,"  %d   |",state->blueOut[i]); }
            if( state->redOut[i] <10 ){ fprintf(strategoLogFile,"   %d   |\n",state->redOut[i]); }
            else{ fprintf(strategoLogFile,"  %d   |\n",state->redOut[i]); }
            PrintStateLine();
        }
        
        fprintf(strategoLogFile,"\t\t                                                                 10 |");
        fprintf(strategoLogFile,"   %d   |",state->blueOut[10]);
        fprintf(strategoLogFile,"   %d   |\n",state->redOut[10]);
        fprintf(strategoLogFile,"\t\t                                                                    ------------------\n");
        
        PrintLine();
        fprintf(strategoLogFile,"\n");
    }
    else{ return 0; }
    return 1;
    
}

int PrintMove(int color,SMove move)
{
    if( strategoLogFile ){
        if( color == ECred ){ fprintf(strategoLogFile,"\t\t\t\t\t\t\t\t\tRouge joue [%d][%d] --> [%d][%d]\n",move.start.line,move.start.col,move.end.line,move.end.col); }
        else{ fprintf(strategoLogFile,"\t\t\t\t\t\t\t\t\tBleu joue [%d][%d] --> [%d][%d]\n",move.start.line,move.start.col,move.end.line,move.end.col); }
    }
    else{ return 0; }
    return 1;
}

int PrintInvalidMove(int color,int nbColorPenalties)
{
    if( strategoLogFile ){
        if( color == ECred ){ fprintf(strategoLogFile,"\t\t\t\t\t\t\t\t!!! Coup invalide : pénalité joueur Rouge(%d)\n",nbColorPenalties); }
        else{ fprintf(strategoLogFile,"\t\t\t\t\t\t\t\t!!! Coup invalide : pénalité joueur Bleu(%d)\n",nbColorPenalties); }
    }
    else{ return 0; }
    return 1;
}

int PrintAttackResult(EColor attackColor,SPos attackerPos,EPiece attackerPiece,SPos victimPos,EPiece victimPiece)
{
    if( strategoLogFile ){
        if( victimPiece == EPflag ){
            if( attackColor == ECred ){fprintf(strategoLogFile,"\t\t\t\t\t\t\tR%d[%d][%d] attaque le drapeau Bleu[%d][%d] ---> Bleu a perdu son drapeau\n",attackerPiece,attackerPos.line,attackerPos.col,victimPos.line,victimPos.col); }
            else{ fprintf(strategoLogFile,"\t\t\t\t\t\t\tB%d[%d][%d] attaque le drapeau Rouge[%d][%d] ---> Rouge a perdu son drapeau\n",attackerPiece,attackerPos.line,attackerPos.col,victimPos.line,victimPos.col); }
        }
        else if( victimPiece == EPbomb ){
            if( attackerPiece == EPminer ){
                if( attackColor == ECred ){fprintf(strategoLogFile,"\t\t\t\t\t\t\tR3[%d][%d] attaque une bombe Bleu[%d][%d] ---> Démineur Rouge désamorce la bombe\n",attackerPos.line,attackerPos.col, victimPos.line,victimPos.col); }
                else{ fprintf(strategoLogFile,"\t\t\t\t\t\t\tB3[%d][%d] attaque une bombe Rouge[%d][%d] ---> Démineur Bleu désamorce la bombe\n",attackerPos.line,attackerPos.col,victimPos.line,victimPos.col); }
            }
            else{
                if( attackColor == ECred ){fprintf(strategoLogFile,"\t\t\t\t\t\t\tR%d[%d][%d] attaque une bombe Bleu[%d][%d] ---> R%d explose\n",attackerPiece,attackerPos.line,attackerPos.col,victimPos.line,victimPos.col,attackerPiece); }
                else{ fprintf(strategoLogFile,"\t\t\t\t\t\t\tB%d[%d][%d] attaque une bombe Rouge[%d][%d] ---> B%d explose\n",attackerPiece,attackerPos.line,attackerPos.col,victimPos.line,victimPos.col,attackerPiece); }
            }
        }
        else if( attackerPiece > victimPiece || (attackerPiece == EPspy && victimPiece == EPmarshal) ){
            if( attackColor == ECred ){
                fprintf(strategoLogFile,"\t\t\t\t\t\t\tR%d[%d][%d] attaque B%d[%d][%d] ---> B%d est éliminé\n",attackerPiece,attackerPos.line,attackerPos.col,victimPiece,victimPos.line,victimPos.col,victimPiece);
            }
            else{
               fprintf(strategoLogFile,"\t\t\t\t\t\t\tB%d[%d][%d] attaque R%d[%d][%d] ---> R%d est éliminé\n",attackerPiece,attackerPos.line,attackerPos.col,victimPiece,victimPos.line,victimPos.col,victimPiece); 
            }
        }
        else if( victimPiece > attackerPiece ){
            if( attackColor == ECred ){
                fprintf(strategoLogFile,"\t\t\t\t\t\t\tR%d[%d][%d] attaque B%d[%d][%d] ---> R%d est éliminé\n",attackerPiece,attackerPos.line,attackerPos.col,victimPiece,victimPos.line,victimPos.col,attackerPiece);
            }
            else{
               fprintf(strategoLogFile,"\t\t\t\t\t\t\tB%d[%d][%d] attaque R%d[%d][%d] ---> B%d est éliminé\n",attackerPiece,attackerPos.line,attackerPos.col,victimPiece,victimPos.line,victimPos.col,attackerPiece); 
            }
        }
        else{
            if( attackColor == ECred ){
                fprintf(strategoLogFile,"\t\t\t\t\t\t\tR%d[%d][%d] attaque B%d[%d][%d] ---> R%d et B%d sont éliminés\n\n",attackerPiece,attackerPos.line,attackerPos.col,victimPiece,victimPos.line,victimPos.col,attackerPiece,victimPiece);
            }
            else{
               fprintf(strategoLogFile,"\t\t\t\t\t\t\tB%d[%d][%d] attaque R%d[%d][%d] ---> B%d et R%d sont éliminés\n\n",attackerPiece,attackerPos.line,attackerPos.col,victimPiece,victimPos.line,victimPos.col,victimPiece,attackerPiece); 
            }
        }
    }
    else{ return 0; }
    return 1;
}

int PrintPenalty(char name[300],int color)
{
    if( strategoLogFile ){
        if( color == ECred ){ fprintf(strategoLogFile,"%s (Rouge) a atteind le nombre maximum de pénalités\n",name); }
        else{ fprintf(strategoLogFile,"%s (Bleu) a atteind le nombre maximum de pénalités\n",name); }
    }
    else{ return 0; }
    return 1; 
}

int PrintMaxMoveReached()
{
    if( strategoLogFile ){
        fprintf(strategoLogFile,"Nombre de coups Maximums atteind\n");
    }
    else{ return 0; }
    return 1;
}

int PrintMatchWinner(char name[300],int color,int game)
{
    if( strategoLogFile ){
        if( color == ECred ){ fprintf(strategoLogFile,"%s (Rouge) remporte la manche %d\n",name,game); }
        else{ fprintf(strategoLogFile,"%s (Bleu) remporte la manche %d\n",name,game); }
    }
    else{ return 0; }
    return 1;
}

int PrintGameWinner(char name[300],int color)
{
    if( strategoLogFile ){
        if( color == ECred ){ fprintf(strategoLogFile,"%s (Rouge) remporte la partie\n",name); }
        else{ fprintf(strategoLogFile,"%s (Bleu) remporte la partie\n",name); }
    }
    else{ return 0; }
    return 1;
}

int CloseLogFile()
{
    if( fclose(strategoLogFile) ){ return 0; }
    return 1;
}


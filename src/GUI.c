#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "GUI.h"

void j1InitPlayer_GUI(char name[50]) {
    if (name) {
        printf("GUI : j1 InitPlayer\n");
    }
}

void j1StartMatch_GUI() {
    printf("GUI : j1 StartMatch\n");
}

void j1StartGame_GUI(const EColor color, EPiece boardInit[4][10]) {
    if (color > 1 && color <= 3 && boardInit) {
        printf("GUI : j1 StartGame\n");
    }
}

void j1EndGame_GUI() {
    printf("GUI : j1 EndGame\n");
}

void j1EndMatch_GUI() {
    printf("GUI : j1 EndMatch\n");
}

SMove j1NextMove_GUI(const SGameState * const gameState) {
    if (gameState) {
        printf("GUI : j1 NextMove\n");
    }
    SMove move;
    return move;
}

void j1AttackResult_GUI(SPos armyPos, EPiece armyPiece, SPos enemyPos, EPiece enemyPiece) {
    if (armyPiece >= 0 && armyPiece < 12 && enemyPiece >= 0 && enemyPiece < 12) {
        printf("GUI : j1 AttackResult\n");
    }
}

void j1Penalty_GUI() {
    printf("GUI : j1 Penalty\n");
}

void j2InitPlayer_GUI(char name[50]) {
    if (name) {
        printf("GUI : j2 InitPlayer\n");
    }
}

void j2StartMatch_GUI() {
    printf("GUI : j2 StartMatch\n");
}

void j2StartGame_GUI(const EColor color, EPiece boardInit[4][10]) {
    if (color > 1 && color <= 3 && boardInit) {
        printf("GUI : j2 StartGame\n");
    }
}

void j2EndGame_GUI() {
    printf("GUI : j2 EndGame\n");
}

void j2EndMatch_GUI() {
    printf("GUI : j2 EndMatch\n");
}

SMove j2NextMove_GUI(const SGameState * const gameState) {
    if (gameState) {
        printf("GUI : j2 NextMove\n");
    }
    SMove move;
    return move;
}

void j2AttackResult_GUI(SPos armyPos, EPiece armyPiece, SPos enemyPos, EPiece enemyPiece) {
    if (armyPiece >= 0 && armyPiece < 12 && enemyPiece >= 0 && enemyPiece < 12) {
        printf("GUI : j2 AttackResult\n");
    }
}

void j2Penalty_GUI() {
    printf("GUI : j2 Penalty\n");
}

void Menu(int *nbJoueur) {
    printf("Print Menu \n");
    SDL_Surface *screen, *menuPic = NULL, *humain = NULL, *ia = NULL, *play = NULL;
    SDL_Rect posMenuPic, posJoueur1, posJoueur2, posRect1, posRect2, posPlay;
    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {255, 255, 255};
    int typeJoueur1, typeJoueur2; //0 = Humain, 1 = IA

    /*
     * Initialistation de la fenêre
     */
    if (SDL_Init(SDL_INIT_VIDEO) == -1 || TTF_Init() == -1) {
        printf("Can't init SDL:  %s\n", SDL_GetError());
    }
    atexit(SDL_Quit);

    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF /* | SDL_FULLSCREEN*/);
    SDL_WM_SetCaption("Stratego", NULL);

    if (screen == NULL) {
        printf("Can't set video mode: %s\n", SDL_GetError());
    }
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

    /*
     * Background
     */
    menuPic = SDL_LoadBMP("ressources/backgroudMenuD.bmp");
    if (menuPic == NULL) {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
    }
    menuPic = SDL_DisplayFormat(menuPic);

    posMenuPic.x = 0;
    posMenuPic.y = 0;
    SDL_BlitSurface(menuPic, NULL, screen, &posMenuPic);


    /*
     * Mise en place des boutons de type de joueurs
     */

    /* Chargement des polices */
    police = TTF_OpenFont("ressources/DejaVuSans.ttf", 30);

    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    humain = TTF_RenderText_Blended(police, "Humain", couleurBlanche);
    ia = TTF_RenderText_Blended(police, "IA", couleurBlanche);

    /*
     * Mise en place
     */
    posJoueur1.x = 200;
    posJoueur1.y = 300;

    posJoueur2.x = 850;
    posJoueur2.y = 300;

    SDL_BlitSurface(humain, NULL, screen, &posJoueur1); /* Blit du texte */
    SDL_BlitSurface(humain, NULL, screen, &posJoueur2); /* Blit du texte */

    typeJoueur1 = 0;
    typeJoueur2 = 0;

    /*
     * Bouton Play
     */
    /* Chargement de la police */
    police = TTF_OpenFont("ressources/DejaVuSans.ttf", 65);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    play = TTF_RenderText_Blended(police, "Play", couleurBlanche);

    posPlay.x = 550;
    posPlay.y = 550;
    SDL_BlitSurface(play, NULL, screen, &posPlay); /* Blit du texte */

    police = TTF_OpenFont("ressources/DejaVuSans.ttf", 30);

    SDL_Flip(screen);

    SDL_Event event;
    int playing = 1;

    while (playing) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) // Choix de l'action à réaliser suivant l'évenement.
            {
                case SDL_QUIT: // Cas du clic sur la croix rouge (en haut a droite)
                    playing = 0;
                    printf("Quitte\n");
                    break;

                case SDL_MOUSEBUTTONUP: // Cas du clic de la souris ..
                    if (event.button.button == SDL_BUTTON_LEFT) {

                        //CASE Humain/Ia 1
                        if (event.button.x > posJoueur1.x && event.button.y > posJoueur1.y
                                && event.button.y < (posJoueur1.y + posJoueur1.h) && event.button.x < (posJoueur1.x + posJoueur1.w)) {
                            printf("Clic Player1\n");
                            if (typeJoueur1 == 0) {
                                SDL_BlitSurface(menuPic, NULL, screen, &posMenuPic);
                                SDL_BlitSurface(play, NULL, screen, &posPlay); /* Blit du texte */
                                SDL_BlitSurface(ia, NULL, screen, &posJoueur1); /* Blit du texte */
                                typeJoueur1 = 1;

                            } else {
                                SDL_BlitSurface(menuPic, NULL, screen, &posMenuPic);
                                SDL_BlitSurface(play, NULL, screen, &posPlay); /* Blit du texte */
                                SDL_BlitSurface(humain, NULL, screen, &posJoueur1); /* Blit du texte */
                                typeJoueur1 = 0;
                            }
                            if (typeJoueur2 == 0) {
                                SDL_BlitSurface(humain, NULL, screen, &posJoueur2); /* Blit du texte */
                            } else
                                SDL_BlitSurface(ia, NULL, screen, &posJoueur2); /* Blit du texte */
                            SDL_Flip(screen);
                        }

                        //CASE Humain/Ia 2
                        if (event.button.x > posJoueur2.x && event.button.y > posJoueur2.y
                                && event.button.y < (posJoueur2.y + posJoueur2.h) && event.button.x < (posJoueur2.x + posJoueur2.w)) {
                            printf("Clic Player2\n");
                            if (typeJoueur2 == 0) {
                                SDL_BlitSurface(menuPic, NULL, screen, &posMenuPic);
                                SDL_BlitSurface(play, NULL, screen, &posPlay); /* Blit du texte */
                                SDL_BlitSurface(ia, NULL, screen, &posJoueur2); /* Blit du texte */
                                typeJoueur2 = 1;
                            } else {
                                SDL_BlitSurface(menuPic, NULL, screen, &posMenuPic);
                                SDL_BlitSurface(play, NULL, screen, &posPlay); /* Blit du texte */
                                SDL_BlitSurface(humain, NULL, screen, &posJoueur2); /* Blit du texte */
                                typeJoueur2 = 0;
                            }
                            if (typeJoueur1 == 0) {
                                SDL_BlitSurface(humain, NULL, screen, &posJoueur1); /* Blit du texte */
                            } else
                                SDL_BlitSurface(ia, NULL, screen, &posJoueur1); /* Blit du texte */
                            SDL_Flip(screen);
                        }

                        //OK
                        if (event.button.x > posPlay.x && event.button.y > posPlay.y
                                && event.button.y < (posPlay.y + posPlay.h) && event.button.x < (posPlay.x + posPlay.w)) {
                            if (typeJoueur1 == 0 && typeJoueur1 == 0) {
                                *nbJoueur = 2;
                            } else if (typeJoueur1 == 1 && typeJoueur1 == 1) {
                                *nbJoueur = 0;
                            } else {
                                *nbJoueur = 1;
                            }
                            printf("Clic Play\n");
                            SDL_Flip(screen);
                            playing = 0;
                        }
                    }
                    break;
            }
        }
    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(humain);
    SDL_FreeSurface(ia);
    SDL_FreeSurface(play);
    SDL_FreeSurface(menuPic);
}


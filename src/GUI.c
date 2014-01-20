#include "GUI.h"

void j1InitPlayer_GUI(char name[50])
{
    if( name ){ 
        printf("GUI : j1 InitPlayer\n");
    }
}

void j1StartMatch_GUI()
{
    printf("GUI : j1 StartMatch\n");
}

void j1StartGame_GUI(const EColor color,EPiece boardInit[4][10])
{
    if( color>1 && color<=3 && boardInit ){
        printf("GUI : j1 StartGame\n");
    }
}

void j1EndGame_GUI()
{
    printf("GUI : j1 EndGame\n");
}

void j1EndMatch_GUI()
{
    printf("GUI : j1 EndMatch\n");
}

SMove j1NextMove_GUI(const SGameState * const gameState)
{
    if( gameState ){
        printf("GUI : j1 NextMove\n");
    }
    SMove move;
    return move;
}

void j1AttackResult_GUI(SPos armyPos,EPiece armyPiece,SPos enemyPos,EPiece enemyPiece)
{
     if( armyPiece>=0 && armyPiece<12 && enemyPiece>=0 && enemyPiece<12 ){
        printf("GUI : j1 AttackResult\n");
     }
}

void j1Penalty_GUI()
{
    printf("GUI : j1 Penalty\n");
}



void j2InitPlayer_GUI(char name[50])
{
    if( name ){
        printf("GUI : j2 InitPlayer\n");
    }
}

void j2StartMatch_GUI()
{
    printf("GUI : j2 StartMatch\n");
}

void j2StartGame_GUI(const EColor color,EPiece boardInit[4][10])
{
    if( color>1 && color<=3 && boardInit ){
         printf("GUI : j2 StartGame\n");
    }
}

void j2EndGame_GUI()
{
    printf("GUI : j2 EndGame\n");
}

void j2EndMatch_GUI()
{
    printf("GUI : j2 EndMatch\n");
}

SMove j2NextMove_GUI(const SGameState * const gameState)
{
    if( gameState ){
        printf("GUI : j2 NextMove\n");
    }
    SMove move;
    return move;
}

void j2AttackResult_GUI(SPos armyPos,EPiece armyPiece,SPos enemyPos,EPiece enemyPiece)
{
     if( armyPiece>=0 && armyPiece<12 && enemyPiece>=0 && enemyPiece<12 ){
        printf("GUI : j2 AttackResult\n");
     }
}

void j2Penalty_GUI()
{
    printf("GUI : j2 Penalty\n");
}

void Menu(int *maxCp,char* pathIA1,char* pathIA2)
{
    printf("Print Menu \n");
    SDL_Surface *screen, *menuPic = NULL, *gender1 = NULL, *gender2 = NULL, *play = NULL;
    SDL_Rect posMenuPic, posJoueur1, posJoueur2, posGender1, posGender2, posPlay;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {255, 255, 255};
    SDL_Color couleurBlanche = {0, 0, 0};
    int typeJoueur1, typeJoueur2; //0 = Humain, 1 = IA

    /*
     * Initialistation de la fenêtre
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
    gender1 = TTF_RenderText_Blended(police, "Humain", couleurNoire);
    gender2 = TTF_RenderText_Blended(police, "IA", couleurBlanche);

    /*
     * Mise en place
     */
    posJoueur1.x = 200;
    posJoueur1.y = 300;

    posJoueur2.x = 850;
    posJoueur2.y = 300;

    /*
     * Bouton Gender1
     */
    //
    /* Mise en place du carré de selection */
    posGender1.x = 200;
    posGender1.y = 300;
    posGender1.h = 35;
    posGender1.w = 120;
    SDL_FillRect(screen, &posGender1, SDL_MapRGB(screen->format, 0, 0, 0));


    /*
     * Bouton Gender2
     */
    /* Mise en place du carré de selection */
    posGender2.x = 850;
    posGender2.y = 300;
    posGender2.h = 35;
    posGender2.w = 120;
    SDL_FillRect(screen, &posGender2, SDL_MapRGB(screen->format, 0, 0, 0));


    SDL_BlitSurface(gender1, NULL, screen, &posJoueur1); /* Blit du texte */
    SDL_BlitSurface(gender1, NULL, screen, &posJoueur2); /* Blit du texte */

    typeJoueur1 = 0;
    typeJoueur2 = 0;

    /*
     * Bouton Play
     */
    /* Chargement de la police */
    police = TTF_OpenFont("DejaVuSans.ttf", 65);
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    play = TTF_RenderText_Blended(police, "Play", couleurNoire);

    posPlay.x = 550;
    posPlay.y = 550;
    SDL_BlitSurface(play, NULL, screen, &posPlay); /* Blit du texte */

    police = TTF_OpenFont("DejaVuSans.ttf", 30);

    SDL_Flip(screen);

    SDL_Event event;
    int playing = 1;

    while (playing) {
        //SDL_WaitEvent(&event); 
        while (SDL_PollEvent(&event)) {
            switch (event.type) // Choix de l'action à réaliser suivant l'évenement.
            {
                case SDL_QUIT: // Cas du clic sur la croix rouge (en haut a droite)
                    playing = 0;
                    printf("Quitte\n");
                    break;

                case SDL_MOUSEBUTTONUP: // Cas du clic de la souris ..
                    if (event.button.button == SDL_BUTTON_LEFT) // gauche !
                    {

                        //CASE Humain/Ia 1
                        if (event.button.x > posGender1.x && event.button.y > posGender1.y
                                && event.button.y < (posGender1.y + posGender1.h) && event.button.x < (posGender1.x + posGender1.w)) {
                            printf("Clic Player1\n");
                            if (typeJoueur1 == 0) {
                                SDL_FillRect(screen, &posGender1, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(gender2, NULL, screen, &posJoueur1); /* Blit du texte */
                                typeJoueur1 = 1;
                            } else {
                                SDL_FillRect(screen, &posGender1, SDL_MapRGB(screen->format, 0, 0, 0));
                                SDL_BlitSurface(gender1, NULL, screen, &posJoueur1); /* Blit du texte */
                                typeJoueur1 = 0;
                            }

                            SDL_Flip(screen);
                        }

                        //CASE Humain/Ia 2
                        if (event.button.x > posGender2.x && event.button.y > posGender2.y
                                && event.button.y < (posGender2.y + posGender2.h) && event.button.x < (posGender2.x + posGender2.w)) {
                            printf("Clic Player2\n");
                            if (typeJoueur2 == 0) {
                                SDL_FillRect(screen, &posGender2, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(gender2, NULL, screen, &posJoueur2); /* Blit du texte */
                                typeJoueur2 = 1;
                            } else {
                                SDL_FillRect(screen, &posGender2, SDL_MapRGB(screen->format, 0, 0, 0));
                                SDL_BlitSurface(gender1, NULL, screen, &posJoueur2); /* Blit du texte */
                                typeJoueur2 = 0;
                            }
                            SDL_Flip(screen);
                        }

                        //OK
                        if (event.button.x > posPlay.x && event.button.y > posPlay.y
                                && event.button.y < (posPlay.y + posPlay.h) && event.button.x < (posPlay.x + posPlay.w)) {
                            if (typeJoueur1 == 0 && typeJoueur1 == 0) {
                            }
                            else if (typeJoueur1 == 1 && typeJoueur1 == 1) {

                            } else {

                            }
                            printf("Clic Play\n");
                            SDL_Flip(screen);
                            playing = 0;
                        }

                    }
                    printf("clique\n");

                    break;
            }
        }
    }
    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(menuPic);
    SDL_FreeSurface(gender1);
    SDL_FreeSurface(gender2);
    SDL_FreeSurface(play);
    
}


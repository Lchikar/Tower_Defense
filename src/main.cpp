#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/Entity.hpp"
#include "../include/Map.hpp"
#include "../include/Building.hpp"
#include "../include/Tower.hpp"
#include "../include/Alien.hpp"
#include "../include/Path.hpp"
#include "../include/Position.hpp"
#include "../include/texture.hpp"
#include "../include/Button.hpp"
#include "../include/IHM.hpp"

#include "../include/const.hpp"

// Dimensions de la fenetre : 1180x750;


int main()  {  
    
	/********************* WINDOW SDL ************************/
    /* Initialisation de la SDL */
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(
            stderr, 
            "Impossible d'initialiser la SDL. Fin du programme.\n");
        exit(EXIT_FAILURE);
    }
  
    /* Ouverture d'une fenetre et creation d'un contexte OpenGL */
    SDL_Surface* surface;
    surface = SDL_SetVideoMode(
        WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, 
        SDL_OPENGL | SDL_GL_DOUBLEBUFFER);
    glViewport(0, 0, (surface)->w, (surface)->h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(
        -GL_VIEW_WIDTH/2, GL_VIEW_WIDTH/2, 
        -GL_VIEW_HEIGHT/2, GL_VIEW_HEIGHT/2);

    if(NULL == surface) {
        fprintf(
            stderr, 
            "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }

    /* Initialisation du titre de la fenetre */
    SDL_WM_SetCaption(WINDOW_TITLE, NULL);

    /* Activation de la transparence des textures */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    /********************************************************/


     
    /*********** Initialisation des textures ****************/
    // Aliens
    GLuint textureAlienNervous = setTexture(filenameNervous);
    GLuint textureAlienFatty = setTexture(filenameFatty);
    // Towers
    GLuint textureTower1 = setTexture(filenameTower1);
    GLuint textureTower2 = setTexture(filenameTower2);
    GLuint textureTower3 = setTexture(filenameTower3);
    GLuint textureTower4 = setTexture(filenameTower4);
    // Buildings
    GLuint textureRadar = setTexture(filenameRadar);
    GLuint textureNavette = setTexture(filenameNavette);
    GLuint textureRobot = setTexture(filenameRobot);
    /*******************************************************/



    /********************** MAP ***************************/
  	// Chargement et traitement de la texture de la map
    Map map;
    GLuint textureMap = map.setMap();
    /******************************************************/



    /************** Initialisation de l'IHM ****************/
    // Button Info
    Button buttonInfo = Button(info);
    GLuint textureButtonInfo = buttonInfo.setButtonTexture();
    // Button Cross
    Button buttonCross = Button(cros);
    GLuint textureButtonCross = buttonCross.setButtonTexture();
    // Button Pause
    Button buttonPause = Button(pause);
    GLuint textureButtonPause = buttonPause.setButtonTexture();
    // Button Play
    Button buttonPlay = Button(play);
    GLuint textureButtonPlay = buttonPlay.setButtonTexture();
    // Coins
    IHM IHMCoins = IHM(coins);
    GLuint textureIHMCoins = IHMCoins.setIHMTexture();
    // Coins
    IHM IHMInterface = IHM(interface);
    GLuint textureInterface = IHMInterface.setIHMTexture();
    /********************************************************/



    /****************** TEST NEW ELEMENTS *******************/
    // New alien
    Alien alienTest = Alien(fatty);

    // New tower
    Tower tower1 = Tower(red);
    Tower tower2 = Tower(green);
    Tower tower3 = Tower(blue);
    Tower tower4 = Tower(yellow);

    // New Building
    Building radarIHM = Building(radar);
    Building navetteIHM = Building(navette);
    Building robotIHM = Building(robot);
    /*******************************************************/


   

    /* Boucle principale */
    int loop = 1;
    while(loop) {
        /* Recuperation du temps au debut de la boucle */
        Uint32 startTime = SDL_GetTicks();
        
        /* Placer ici le code de dessin */
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix();
            map.drawMap(textureMap, GL_VIEW_WIDTH, GL_VIEW_HEIGHT);
        glPopMatrix();


		/***************** DRAW IHM ******************/
		// Buttons
		buttonInfo.drawButton(textureButtonInfo);
		buttonPause.drawButton(textureButtonPause);
		// Interface
		IHMCoins.drawIHM(textureIHMCoins);
		IHMInterface.drawIHM(textureInterface);
		/*********************************************/
        

        tower1.drawEntity(textureTower1, 530, 200);
        tower2.drawEntity(textureTower2, 530, 115);
        tower3.drawEntity(textureTower3, 530, 30);
        tower4.drawEntity(textureTower4, 530, -55);
        radarIHM.drawEntity(textureRadar, 530, -140);
        navetteIHM.drawEntity(textureNavette, 530, -225);
        robotIHM.drawEntity(textureRobot, 530, -310);

        alienTest.drawEntity(textureAlienFatty, -500, 140);

        //printf("position x de bouton info: %f\n", buttonInfo.getPos().getX());
    	//printf("position y de bouton info: %f\n", buttonInfo.getPos().getY());

    	//printf("position x de bouton radar: %f\n", radarIHM.getPos().getX());
    	//printf("position y de bouton radar: %f\n", radarIHM.getPos().getY());



        /* Echange du front et du back buffer : mise a jour de la fenetre */
        SDL_GL_SwapBuffers();
        

        /* Boucle traitant les evenements */
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            /* L'utilisateur ferme la fenetre : */
            if(e.type == SDL_QUIT) {
                loop = 0;
                break;
            }
        
            if( e.type == SDL_KEYDOWN 
                && (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE)) {
                loop = 0; 
                break;
            }
            
            /* Quelques exemples de traitement d'evenements : */
            switch(e.type) {
                /* Clic souris */
                case SDL_MOUSEBUTTONUP:
                    //printf("clic en (%d, %d)\n", e.button.x, e.button.y);
                	//printf("position x de bouton info: %f\n", buttonInfo.getPos().getX());
                	//printf("position y de bouton info: %f\n", buttonInfo.getPos().getY());
					//printf("distance %f\n", buttonInfo.getPos().dist(Position(e.button.x-(GL_VIEW_WIDTH/2), e.button.y+(GL_VIEW_HEIGHT/2)-60)));
					if (buttonInfo.getPos().dist(Position(e.button.x-(GL_VIEW_WIDTH/2), e.button.y+(GL_VIEW_HEIGHT/2)-60)) <= 20) {
						printf("J'ai cliqué sur le bouton Info\n");
						buttonCross.drawButton(textureButtonCross);
					}
					if (buttonPause.getPos().dist(Position(e.button.x-(GL_VIEW_WIDTH/2), e.button.y+(GL_VIEW_HEIGHT/2)-60)) <= 20) {
						printf("J'ai cliqué sur le bouton Pause\n");
						buttonPlay.drawButton(textureButtonPlay);
					}
                
                    
                    break;
                
                /* Touche clavier */
                case SDL_KEYDOWN:
                    printf("touche pressee (code = %d)\n", e.key.keysym.sym);
                    break;
                    
                default:
                    break;
            }
        }

        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        /* Si trop peu de temps s'est ecoule, on met en pause le programme */
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
    }



    /********** Libération des données GPU *****************/
    // Delete textures
    // Map
	glDeleteTextures(1, &textureMap);
    // Aliens
	glDeleteTextures(1, &textureAlienFatty);
    glDeleteTextures(1, &textureAlienNervous);
    // Towers
	glDeleteTextures(1, &textureTower1);
    glDeleteTextures(1, &textureTower2);
    glDeleteTextures(1, &textureTower3);
    glDeleteTextures(1, &textureTower4);
    // Buildings
    glDeleteTextures(1, &textureRadar);
    glDeleteTextures(1, &textureNavette);
    glDeleteTextures(1, &textureRobot);
	// Delete IHM
	glDeleteTextures(1, &textureButtonInfo);
	glDeleteTextures(1, &textureButtonPause);
	glDeleteTextures(1, &textureButtonPlay);
	glDeleteTextures(1, &textureButtonCross);
	glDeleteTextures(1, &textureIHMCoins);
	glDeleteTextures(1, &textureInterface);
	/**********************************************************/


    /* Liberation des ressources associees a la SDL */ 
    SDL_Quit();
    
    return EXIT_SUCCESS;
}

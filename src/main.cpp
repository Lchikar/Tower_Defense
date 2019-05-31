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
#include <string.h>
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
#include "../include/Graph.hpp"
#include "../include/InGame.hpp"

#include "../include/const.hpp"

// Dimensions de la fenetre : 1180x750;


int main(int argc, char** argv){

    if(argc != 2){
        fprintf(stderr, "Veuillez renseigner le chemin du fichier .itd\n");
        return EXIT_FAILURE;
    } 

    if(0 != strcmp(&(argv[1][strlen(argv[1])-4]), ".itd")){
        fprintf(stderr, "Veuillez renseigner le chemin du fichier .itd\n");
        return EXIT_FAILURE;
    }


    Graph G = Graph();
    int nbNodes;
    vector<vector<int>> nodes = G.read_nodes(string(argv[1]), &nbNodes);
    if(nodes.empty()){
        fprintf(stderr, "Fail to read %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // for (int i = 0; i < nodes.size(); i++){
    //     cout << "node " << i << ": ";
    //     for (int j = 0; j < nodes[i].size(); j++){
    //         cout << nodes[i][j] << " ";
    //     }
    // cout << "\n";
    // }
    // printf("\n");

    for(int u = 0; u < nbNodes; u++){
        G.addVertex(u);
    }
    for(int u = 0; u < nbNodes; u++){
        for(int v = 3; v < nodes[u].size(); v++){
            Position u_p = Position(float(nodes[u][1]),float(nodes[u][2]));
            Position v_p = Position(float(nodes[nodes[u][v]][1]),float(nodes[nodes[u][v]][2]));
            G.addEdge(u,nodes[u][v], u_p.dist(v_p));
        }
    }

    // for (int i = 0; i < G.getAdj().size(); i++){
    //     cout << "node " << i << ": ";
    //     for (int j = 0; j < G.getAdj()[i].size(); j++){
    //         cout << "(" << G.getAdj()[i][j].first << ", " << G.getAdj()[i][j].second << ") ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    

    InGame game = InGame();
    int nbTowers = 0;
    vector<pair<int,int>> edges = G.edges();


    

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
    // Interface
    IHM IHMInterface = IHM(interface);
    GLuint textureInterface = IHMInterface.setIHMTexture();
    // User Guide
    IHM guide = IHM(userGuide);
    GLuint textureGuide = guide.setIHMTexture();
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
        printf("nbtours %d\n",game.getTowers().size() );
        for(int i = 0; i < game.getTowers().size(); i++){
            printf("Tour %d: (%f,%f)\n", i,game.getTowers()[i].getPos().getX(), game.getTowers()[i].getPos().getY());
        }

        /* Recuperation du temps au debut de la boucle */
        Uint32 startTime = SDL_GetTicks();
        
        /****************************************
        *************** DRAW ********************
        *****************************************/
        glClear(GL_COLOR_BUFFER_BIT);


        /***************** DRAW MAP ******************/
        map.drawMap(textureMap, GL_VIEW_WIDTH, GL_VIEW_HEIGHT);
        /*********************************************/


        /***************** DRAW IHM ****************/
        IHMCoins.drawIHM(textureIHMCoins);
        IHMInterface.drawIHM(textureInterface);
        /*********************************************/


        /************** DRAW TOWER IHM **************/
        tower1.drawTowerIHM(textureTower1);
        tower2.drawTowerIHM(textureTower2);
        tower3.drawTowerIHM(textureTower3);
        tower4.drawTowerIHM(textureTower4);
        /********************************************/
    

        /************ DRAW BUILDING IHM *************/
        radarIHM.drawBuildingIHM(textureRadar);
        navetteIHM.drawBuildingIHM(textureNavette);
        robotIHM.drawBuildingIHM(textureRobot);
        /*********************************************/


        alienTest.move(Position(-500, 140));
        alienTest.drawEntity(textureAlienFatty);



        /***************** DRAW BUTTON ****************/
        if (!buttonInfo.getIsClick()) {
            buttonInfo.drawButton(textureButtonInfo);
        } else {
            buttonCross.drawButton(textureButtonCross);
            guide.drawIHM(textureGuide);
        }
        if (!buttonPause.getIsClick()) {
            buttonPause.drawButton(textureButtonPause);
        } else {
            buttonPlay.drawButton(textureButtonPlay);
        }
        /*********************************************/


        /* Echange du front et du back buffer : mise a jour de la fenetre */
        SDL_GL_SwapBuffers();
        



        /*************** Boucle traitant les evenements ***************/
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

                    //printf("mouse (%d,%d)\n", e.button.x, e.button.y);
                    //printf("mouse (%f,%f)\n", (e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    //printf("position x de tower1: %f\n", tower1.getPos().getX());
                	//printf("position y de tower1: %f\n", tower1.getPos().getY());
					//printf("distance %f\n", buttonInfo.getPos().dist(Position(e.button.x-(GL_VIEW_WIDTH/2), e.button.y+(GL_VIEW_HEIGHT/2)-60)));
					
                    /*
                    if (buttonInfo.getPos().dist(Position(mouseX, mouseY)) <= 20) {
						printf("J'ai cliqué sur le bouton Info\n");
						buttonCross.drawButton(textureButtonCross);
					} 
                    */

                    /* Buttons IHM */
                    buttonInfo.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    buttonCross.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    buttonPause.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    buttonPlay.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    
                    /* Tower */
                    tower1.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    tower2.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    tower3.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    tower4.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    /* Building */
                    radarIHM.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    navetteIHM.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    robotIHM.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    
                    if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(tower1.getPos()) > 25){
                        if(tower1.getIsClick()) {
                            printf("Achat tour 1\n");
                            game.addTowers(red, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                            tower1.setIsClick(false);
                        }
                    }
                    if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(tower2.getPos()) > 25){
                        if(tower2.getIsClick()) {
                            printf("Achat tour 2\n");
                            game.addTowers(red, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                            tower2.setIsClick(false);
                        }
                    }if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(tower3.getPos()) > 25){
                        if(tower3.getIsClick()) {
                            printf("Achat tour 3\n");
                            game.addTowers(red, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                            tower3.setIsClick(false);
                        }
                    }if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(tower4.getPos()) > 25){
                        if(tower4.getIsClick()) {
                            printf("Achat tour 4\n");
                            game.addTowers(red, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                            tower4.setIsClick(false);
                        }
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
        /****************************************************************************/


        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        /* Si trop peu de temps s'est ecoule, on met en pause le programme */
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
    }


    /************ Libération des données GPU *****************/
    // Delete textures
    // Map
	glDeleteTextures(1, &textureMap);
    // Delete IHM
    glDeleteTextures(1, &textureButtonInfo);
    glDeleteTextures(1, &textureButtonPause);
    glDeleteTextures(1, &textureButtonPlay);
    glDeleteTextures(1, &textureButtonCross);
    glDeleteTextures(1, &textureIHMCoins);
    glDeleteTextures(1, &textureInterface);
    glDeleteTextures(1, &textureGuide);
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
	/**********************************************************/


    /* Liberation des ressources associees a la SDL */ 
    SDL_Quit();
    





    return EXIT_SUCCESS;
}

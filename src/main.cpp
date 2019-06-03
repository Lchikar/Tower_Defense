#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <unistd.h>

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


bool estConstructible(Position pos_e, vector<vector<int>> nodes, vector<pair<int,int>> edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        printf("\tEDGE(%d,%d)\n", u, v);

        printf("Position %d (%f,%f) --- %d (%f,%f)\n", u, nodes[u][1] ,nodes[u][2], v, nodes[v][1],nodes[v][2]);

        Position pos_u, pos_v, pos_e;

        pos_u = Position(nodes[u][1],nodes[u][2]);
        pos_v = Position(nodes[v][1],nodes[v][2]);


        Position pos_ut = Position(pos_e.getX()-pos_u.getX(), pos_e.getY()-pos_u.getY());
        Position pos_ev = Position(pos_v.getX()-pos_e.getX(), pos_v.getY()-pos_e.getY());
        Position pos_uv = Position(pos_v.getX()-pos_u.getX(), pos_v.getY()-pos_u.getY());

        if(0 == pos_ut.scalaire(pos_ev)){
            if(0 < pos_uv.vectoriel(pos_ut) &&
                pos_uv.vectoriel(pos_ut) < pos_uv.vectoriel(pos_uv) )
                fprintf(stderr, "Zone non constructible\n");
                return false;
        }
    }

    return true;
}


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
        // printf("Node %d (%d,%d) ---> ", u, nodes[u][1], nodes[u][2]);
        nodes[u][1] = float(nodes[u][1]-(GL_VIEW_WIDTH/2));
        nodes[u][2] = -float((nodes[u][2]-(GL_VIEW_HEIGHT/2)));
        // printf("Node %d (%f,%f)\n", u, float(nodes[u][1]), float(nodes[u][2]));
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
    

    Position pos_init_aliens = Position(float(nodes[0][1]),float(nodes[0][2]));
    InGame game = InGame(G, pos_init_aliens);
    for(int i = 0; i < game.getAliens().size(); i++){
        game.getAlien(i)->setPos(Position(float(nodes[game.getAlien(i)->getNextStep(0)->first][1]),float(nodes[game.getAlien(i)->getNextStep(0)->first][2])));
    }
    // for(int i = 0; i < game.getAliens().size(); i++){
    //     Alien alien = game.getAliens()[i];
    //     printf("Noeud %d (%f,%f)\n", alien.getPath()[0].first,float(nodes[alien.getPath()[0].first][1]),float(nodes[alien.getPath()[0].first][2]));
    //     printf("Position alien %d --> (%f,%f)\n", i, alien.getPos().getX(), alien.getPos().getY());
    // }
    int nbTowers = 0;
    vector<pair<int,int>> edges = G.edges();
    // printf("nb edges %d\n", edges.size());
    // for(int i = 0; i < edges.size(); i++)
    //     printf("(%d,%d)\n", edges[i].first,edges[i].second);


    

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

    /* Initialisation de GLUT pour l'affichage de texte */
    glutInit(&argc, argv);
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
    Button buttonPause = Button(pause_game);
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
    // Window Winner
    IHM win = IHM(winner);
    GLuint textureWinner = win.setIHMTexture();
    // Window Game over
    IHM gameOver = IHM(gameover);
    GLuint textureGameOver = gameOver.setIHMTexture();

    // Towers
    Tower tower1 = Tower(red);
    Tower tower2 = Tower(green);
    Tower tower3 = Tower(blue);
    Tower tower4 = Tower(yellow);
    // Buildings
    Building radarIHM = Building(radar);
    Building navetteIHM = Building(navette);
    Building robotIHM = Building(robot);
/*************************************************************/

   
    /* Boucle principale */
    int loop = 1;
    int nbloop = 0;
    while(loop){ 
        nbloop++;
        if(game.getAliens().size() == 0){
            // printf("*****NEW WAVE*****\n");
            game.updateWaves();
        }
        
        /**************** DRAW WIN OR GAME OVER **************/
        if(game.getWaves() == 50){
            // printf("*****WIN*****\n");
            win.drawIHM(textureWinner);
            sleep(10);
            break;
        }
        if(game.getLife() <= 0){
            // printf("*****LOOSE*****\n");
            gameOver.drawIHM(textureGameOver);
            sleep(10);
            break;
        }
        /***********************************************************
        ************************************************************
        ***********************************************************/
        
        // for(int i = 0; i < game.getAliens().size(); i++){
        //     Alien* alien = (game.getAlien(i));
        //     printf("\tPosition alien %d --> (%f,%f)\n", i, alien->getPos().getX(), alien->getPos().getY());
        //     printf("\tPath : ");
        //     for(int j = 0; j < alien->getPath().size(); j++)
        //         printf("(%d,%d) ", alien->getNextStep(j)->first, alien->getNextStep(j)->second);
        //     printf("\n");
        // }
  

        /* Recuperation du temps au debut de la boucle */
        Uint32 startTime = SDL_GetTicks();

        usleep(200000);


        //calcul risque random
        if(0 == nbloop%3){
            for(int i = 0; i < edges.size(); i++){
               int weight = rand()%10 +1;
               G.update_weight(edges[i].first,edges[i].second, 
                   G.weight(edges[i].first,edges[i].second)*weight);      
            }    
        }
               

        //Update chemins aliens
        for(int i = 0; i < game.getAliens().size(); i++){
            Alien* curr_alien = (game.getAlien(i));
            int curr_node = curr_alien->getNextStep(0)->first;
            // printf("\tCurrent node %d\n", curr_node);
            Position pos_curr_node = Position(float(nodes[curr_node][1]),float(nodes[curr_node][2])); 
            
            if(curr_alien->getPos().dist(pos_curr_node) <= 7){
                // printf("\tAlien %d a atteint le noeud %d\n", i, curr_node);
                if(curr_node < nbNodes-1){
                    // printf("*****NODE %d *******\n", curr_node);
                    curr_alien->updatePath(G);
                    curr_alien->setPos(pos_curr_node);

                    // printf("\tNew current node %d\n", curr_alien->getNextStep(0)->first);
                    // printf("\tPath : ");
                    // for(int j = 0; j < curr_alien->getPath().size(); j++)
                    //     printf("(%d,%d) ", curr_alien->getNextStep(j)->first, curr_alien->getNextStep(j)->second);
                    // printf("\n");
                }
                else {
                    // printf("*********LOOSE LIFE***********\n");
                    game.setLife(-curr_alien->getDamage());
                    game.deleteAliens(i);
                    break;
                }
            }

        }

        
        
        /***********************************************************
        ************************* DRAW *****************************
        ***********************************************************/
        glClearColor(0,0,0,0);
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


        /************** DRAW MONEY INGAME **************/
        char argent[10];
        sprintf(argent, "%d $", game.getMoney()); 
        vBitmapOutput(510, 275, argent, GLUT_BITMAP_HELVETICA_18);
        /*********************************************/


        /********** DRAW TOWERS IN GAME ***************/
        for(int i = 0; i < game.getTowers().size(); i++){
            Tower tour = game.getTowers()[i];
            //printf("Couleur tour %d --> %d\n", i, tour.getColor());
            switch (tour.getColor()){
                case red: tour.drawEntity(textureTower1);
                            break; 
                case green: tour.drawEntity(textureTower2);
                            break;
                case blue: tour.drawEntity(textureTower3);
                            break;
                case yellow: tour.drawEntity(textureTower4);
                            break;
                default: ;
            }
        } 
        /************************************************/

        /*********** DRAW BUILDINGS INGAME **************/
        for(int i = 0; i < game.getBuildings().size(); i++){
            Building batiment = game.getBuildings()[i];
            //printf("Batiment %d --> %d\n", i, batiment.getType());
            switch (batiment.getType()){
                case radar: batiment.drawEntity(textureRadar);
                            break; 
                case navette: batiment.drawEntity(textureNavette);
                            break;
                case robot: batiment.drawEntity(textureRobot);
                            break;
                default: ;
            }
        } 
        /*************************************************/

        /*********** DRAW ALIENS INGAME **************/
        for(int i = 0; i < game.getAliens().size(); i++){
            Alien* curr_alien = game.getAlien(i);
            if(curr_alien->getAlienType() == fatty)
                curr_alien->drawEntity(textureAlienFatty);
            else
                curr_alien->drawEntity(textureAlienNervous);
        }
        /*********************************************/


        /****************** DRAW BUTTON ******************/
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
        /***************************************************/


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
            

                    if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(tower1.getPos()) > 25){
                        if(tower1.getIsClick()) {
                            printf("Achat tour 1\n");
                            if(estConstructible(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))), nodes, edges)){
                                if(game.getMoney() >= tower1.getPrice()){
                                    game.addTowers(red, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                                    tower1.setIsClick(false);
                                    game.setMoney(-tower1.getPrice());
                                }                        }
                            }

                    }
                    if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(tower2.getPos()) > 25){
                        if(tower2.getIsClick()) {
                            printf("Achat tour 2\n");
                            if(estConstructible(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))), nodes, edges)){                            
                                if(game.getMoney() >= tower2.getPrice()){
                                    game.addTowers(green, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                                    tower2.setIsClick(false);
                                    game.setMoney(-tower2.getPrice());
                                }
                            }
                        }
                    }if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(tower3.getPos()) > 25){
                        if(tower3.getIsClick()) {
                            printf("Achat tour 3\n");
                            if(estConstructible(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))), nodes, edges)){                            
                                if(game.getMoney() >= tower3.getPrice()){
                                    game.addTowers(blue, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                                    tower3.setIsClick(false);
                                    game.setMoney(-tower3.getPrice());
                                }
                            }
                        }
                    }if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(tower4.getPos()) > 25){
                        if(tower4.getIsClick()) {
                            printf("Achat tour 4\n");
                            if(estConstructible(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))), nodes, edges)){                            
                                if(game.getMoney() >= tower4.getPrice()){
                                    game.addTowers(yellow, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                                    tower4.setIsClick(false);
                                    game.setMoney(-tower4.getPrice());
                                }
                            }
                        }
                    }

                    /* Building */
                    radarIHM.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    navetteIHM.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    robotIHM.click((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2)));
                    if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(radarIHM.getPos()) > 25){
                        if(radarIHM.getIsClick()) {
                            printf("Achat radar\n");
                            if(estConstructible(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))), nodes, edges)){
                                if(game.getMoney() >= radarIHM.getPrice()){
                                    game.addBuildings(radar, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                                    radarIHM.setIsClick(false);
                                    game.setMoney(-radarIHM.getPrice());
                                }
                            }
                        }
                    }
                    if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(navetteIHM.getPos()) > 25){
                        if(navetteIHM.getIsClick()) {
                            printf("Achat navette\n");
                            if(estConstructible(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))), nodes, edges)){
                                if(game.getMoney() >= navetteIHM.getPrice()){
                                    game.addBuildings(navette, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                                    navetteIHM.setIsClick(false);
                                    game.setMoney(- navetteIHM.getPrice());
                                }
                            }
                        }
                    }if(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))).dist(robotIHM.getPos()) > 25){
                        if(robotIHM.getIsClick()) {
                            printf("Achat robot\n");
                            if(estConstructible(Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))), nodes, edges)){
                                if(game.getMoney() >= robotIHM.getPrice()){
                                    game.addBuildings(robot, Position((e.button.x-(GL_VIEW_WIDTH/2)), -(e.button.y-(GL_VIEW_HEIGHT/2))));
                                    robotIHM.setIsClick(false);
                                    game.setMoney(-robotIHM.getPrice());
                                }
                            }
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

        
        /*********** UPDATE ALIENS POSITION **************/
        for(int i = 0; i < game.getAliens().size(); i++){
            Alien* curr_alien = game.getAlien(i);
            Position curr_pos = curr_alien->getPos();
            int dest = curr_alien->dest();
            int speed = curr_alien->getSpeed();

            // printf("Actuelle position (%f,%f)\n", curr_pos.getX(), curr_pos.getY());
            // printf("Destination %d (%f,%f)\n", dest, float(nodes[dest][1]),float(nodes[dest][2]));
            // printf("Speed %d\n", speed);

            Position pos_dest = Position(float(nodes[dest][1]),float(nodes[dest][2]));
            if(pos_dest.getX() < curr_pos.getX()){
                // printf("\tGO WEST\n");
                // printf("\tMOVE to (%f,%f)\n", float(curr_pos.getX()-float(speed)), float(curr_pos.getY()));
                curr_alien->setPos(Position(float(curr_pos.getX()-float(speed)), float(curr_pos.getY())));
            }
            else if(pos_dest.getX() > curr_pos.getX()){
                // printf("\tGO EAST\n");
                // printf("\tMOVE to (%f,%f)\n", float(curr_pos.getX()+float(speed)), float(curr_pos.getY()));
                curr_alien->setPos(Position(float(curr_pos.getX()+float(speed)), float(curr_pos.getY())));
            }
            if(pos_dest.getY() < curr_pos.getY()){
                // printf("\tGO SOUTH\n");
                // printf("\tMOVE to (%f,%f)\n", float(curr_pos.getX()), float(curr_pos.getY()-float(speed)));
                curr_alien->setPos(Position(float(curr_pos.getX()), float(curr_pos.getY()-float(speed))));
            }
            else if(pos_dest.getY() > curr_pos.getY()){
                // printf("\tGO NORTH\n");
                // printf("\tMOVE to (%f,%f)\n", float(curr_pos.getX()), float(curr_pos.getY()+float(speed)));
                curr_alien->setPos(Position(float(curr_pos.getX()), float(curr_pos.getY()+float(speed)))); 
            }
            
            // printf("Nouvelle position alien %d --> (%f,%f)\n\n", i, curr_alien->getPos().getX(), curr_alien->getPos().getY());                       
        }
        

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
    glDeleteTextures(1, &textureWinner);
    glDeleteTextures(1, &textureGameOver);
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

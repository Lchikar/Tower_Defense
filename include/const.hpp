#pragma once

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

#include "../include/texture.hpp"

/* Dimensions initiales et titre de la fenetre */
static const unsigned int WINDOW_WIDTH = 1180;
static const unsigned int WINDOW_HEIGHT = 750;
static const char WINDOW_TITLE[] = "IMars Attak";


/* Espace fenetre virtuelle */
static const float GL_VIEW_WIDTH = 1180;
static const float GL_VIEW_HEIGHT = 750;

/* Nombre de bits par pixel de la fenetre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

/* Filename textures */
// ALiens
static const char* filenameNervous = "./img/assets/textAlienNervous.png";
static const char* filenameFatty = "./img/assets/textAlienFatty.png";
// Tower
static const char* filenameTower1 = "./img/assets/textTower1.png";
static const char* filenameTower2 = "./img/assets/textTower2.png";
static const char* filenameTower3 = "./img/assets/textTower3.png";
static const char* filenameTower4 = "./img/assets/textTower4.png";
// Buildings
static const char* filenameRadar = "./img/assets/textBuildingRadar.png";
static const char* filenameNavette = "./img/assets/textBuildingNavette.png";
static const char* filenameRobot = "./img/assets/textBuildingRobot.png";
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <fstream>

#include "../include/Map.hpp"
#include "../include/texture.hpp"

using namespace std;

const char* filenameMap = "./img/assets/textMap_1180x750.png";

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* contructor */
Map::Map(){};

/* destructor */
Map::~Map(){};



/****************************************
*************** DRAW ********************
*****************************************/
/* initialisation de la texture */
GLuint Map::setMap() {
	GLuint textureID = setTexture(filenameMap); 
	return textureID;
}

/* affichage de la texture */
void Map::drawMap(GLuint textureID, float x, float y){
	glPushMatrix();
		drawTexture(textureID, x, y);
	glPopMatrix();
}
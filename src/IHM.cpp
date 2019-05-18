#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "../include/IHM.hpp"
#include "../include/texture.hpp"

using namespace std;

const char* filenameButtonInfo = "./img/assets/textButtonInfo.png";
const char* filenameButtonPause = "./img/assets/textButtonPause.png";
const char* filenameButtonPlay = "./img/assets/textButtonPlay.png";
const char* filenameButtonCross = "./img/assets/textButtonCross.png";
const char* filenameCoins = "./img/assets/textCoins.png";
const char* filenameInterfaceBG = "./img/assets/textInterfaceBG_100x552.png";

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* Contructor */
IHM::IHM() {};

/* Destructor */
IHM::~IHM(){};

/****************************************
*************** DRAW ********************
*****************************************/

/* initialisation de la texture ButtonInfo */
GLuint IHM::setButtonInfo() {
	GLuint textureButtonInfo = setTexture(filenameButtonInfo);
	return textureButtonInfo;
}
/*
void IHM::drawButtonInfo(GLuint textureID, float x, float y) {
	drawTexture(textureButtonInfo, 40, 40);
}
*/
/* initialisation des textures */
void IHM::setIHM() {
	GLuint textureButtonInfo = setButtonInfo();
}

void IHM::drawIHM() {
	drawTexture(textureButtonInfo, 40, 40);
}

void IHM::deleteIHM() {
	glDeleteTextures(1, &textureButtonInfo);
}
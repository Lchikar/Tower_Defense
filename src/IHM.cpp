#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "../include/IHM.hpp"
#include "../include/texture.hpp"

using namespace std;

const char* filenameCoins = "./img/assets/textCoins.png";
const char* filenameInterface = "./img/assets/textInterfaceBG_100x552.png";
const char* filenameUserGuide = "./img/assets/textUserGuide_1180x750.png";

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* Contructor */
IHM::IHM() {};

/*  */
IHM::IHM(IHMType type){
	this->type = type;
}

/* Destructor */
IHM::~IHM(){};


/****************************************
*************** DRAW ********************
*****************************************/
/* initialisation de la texture */
GLuint IHM::setIHMTexture() {
	GLuint textureID;
	if(type == userGuide) {
		textureID = setTexture(filenameUserGuide);
		return textureID;
	}
	if(type == coins) {
		textureID = setTexture(filenameCoins);
		return textureID;
	}
	else{
		textureID = setTexture(filenameInterface);
		return textureID;
	}
}

void IHM::drawIHM(GLuint textureID) {
	float x, y, w, h;
	if(type == coins) {
		x = 530;
		y = 280;
		w = 100;
		h = 40;
	}
	if(type == interface) {
		x = 530;
		y = -60;
		w = 100;
		h = 600;
	}
	glPushMatrix();
	glTranslatef(x, y, 0);
	drawTexture(textureID, w, h);
	glPopMatrix();
}

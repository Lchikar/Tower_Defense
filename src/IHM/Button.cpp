#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "../../include/IHM/Button.hpp"
#include "../../include/texture.hpp"

using namespace std;

const char* filenameButtonInfo = "./img/assets/textButtonInfo.png";
const char* filenameButtonPause = "./img/assets/textButtonPause.png";
const char* filenameButtonPlay = "./img/assets/textButtonPlay.png";
const char* filenameButtonCross = "./img/assets/textButtonCross.png";
const char* filenameCoins = "./img/assets/textCoins.png";
const char* filenameInterface = "./img/assets/textInterfaceBG_100x552.png";

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* Contructor */
Button::Button() {};

/*  */
Button::Button(ButtonType type){
	this->type = type;
}

/* Destructor */
Button::~Button(){};


/****************************************
*************** DRAW ********************
*****************************************/
/* initialisation de la texture */
GLuint Button::setButtonTexture() {
	GLuint textureID;
	if(type == info) {
		textureID = setTexture(filenameButtonInfo);
		return textureID;
	}
	if(type == play) {
		textureID = setTexture(filenameButtonPlay);
		return textureID;
	}
	if(type == pause) {
		textureID = setTexture(filenameButtonPause);
		return textureID;
	}
	if(type == cros) {
		textureID = setTexture(filenameButtonCross);
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

void Button::drawButton(GLuint textureID) {
	float x, y;
	float w = 40;
	float h = 40;
	if(type == info) {
		x = 560;
		y = 345;
	}
	if(type == pause) {
		x = 500;
		y = 345;
	}
	if(type == play) {
		x = 500;
		y = 345;
	}
	if(type == cros) {
		x = 560;
		y = 345;
	}
	if(type == coins) {
		x = 530;
		y = 280;
		w = 100;
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

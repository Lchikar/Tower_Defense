#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "../include/Button.hpp"
#include "../include/Entity.hpp"
#include "../include/texture.hpp"

using namespace std;

const char* filenameButtonInfo = "./img/assets/textButtonInfo.png";
const char* filenameButtonPause = "./img/assets/textButtonPause.png";
const char* filenameButtonPlay = "./img/assets/textButtonPlay.png";
const char* filenameButtonCross = "./img/assets/textButtonCross.png";

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* Contructor */
Button::Button() {};

/*  */
Button::Button(ButtonType type){
	this->type = type;
	this->isClick = false;
	setWidth(40);
	setHeight(40);
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
	if(type == pause_game) {
		textureID = setTexture(filenameButtonPause);
		return textureID;
	}
	if(type == cros) {
		textureID = setTexture(filenameButtonCross);
		return textureID;
	}
}

void Button::drawButton(GLuint textureID) {
	float x, y;
	if(type == info) {
		x = 560;
		y = 345;
	}
	if(type == pause_game) {
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
	this->move(Position(x, y));
	glPushMatrix();
	drawEntity(textureID);
	glPopMatrix();
}


/****************************************
***************** CLICK *****************
*****************************************/
void Button::click(float mouseX, float mouseY) {
	if (this->getPos().dist(Position(mouseX, mouseY)) <= 20) {
		this->isClick = !this->isClick;
		printf("J'ai cliqué sur un bouton\n");
	}
} 


/****************************************
*************** GET & SET ****************
*****************************************/
bool Button::getIsClick() {
	bool isClick = this->isClick;
	return isClick;
}

void Button::setIsClick(bool isClick){
	this->isClick = isClick;
}
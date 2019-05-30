#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "../include/Entity.hpp"
#include "../include/Path.hpp"
#include "../include/Alien.hpp"

using namespace std;

// const char* filenameNervous = "./img/assets/textAlienNervous.png";
// const char* filenameFatty = "./img/assets/textAlienFatty.png";

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* Contructor */
Alien::Alien(AlienType type){
	this->type = type;
	if(type == fatty){
		pv =  150;
		reward = 100;
		speed = 20;
	} else {
		pv =  50;
		reward = 50;
		speed = 100;
	}
	setWidth(35);
	setHeight(35);
}
/* Destructor */
Alien::~Alien(){};


/****************************************
*************** DRAW ********************
*****************************************/
/*
//initialisation de la texture
GLuint Alien::setAlien() {
	GLuint textureID;
	if(type == fatty) {
		textureID = setTexture(filenameFatty);
		return textureID;
	} 
	else{
		textureID = setTexture(filenameNervous);
		return textureID;
	}
}
*/
/* affichage de la texture 
void Alien::drawAlien(GLuint textureID) {
	drawTexture(textureID, 35, 35);
}
*/



/****************************************
************** GET & SET ****************
*****************************************/
int Alien::getPv() {
	int pv = this->pv;
	return pv;
}

int Alien::getReward() {
	int reward = this->reward;
	return reward;
}

int Alien::getSpeed() {
	int speed = this->speed;
	return speed;
}

AlienType Alien::getAlienType() {
	AlienType type = this->type;
	return type;
}

void Alien::setPv(int pv){
	this->pv = pv;
}

void Alien::setReward(int reward) {
	this->reward = reward;
}

void Alien::setSpeed(int speed) {
	this->speed = speed;
}

void Alien::setAlienType(AlienType type) {
	this->type = type;
}
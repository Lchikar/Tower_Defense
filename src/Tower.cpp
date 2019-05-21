#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "../include/Entity.hpp"
#include "../include/Tower.hpp"

using namespace std;

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* Contructor */
Tower::Tower(ColorType type) {
	this->type = type;
	if(type == red){
		damage = 3;
		range = 2;
		shotRate = 1;
		price = 5;
	}
	if(type == green){
		damage = 2;
		range = 1;
		shotRate = 3;
		price = 5;
	}
	if(type == yellow){
		damage = 1;
		range = 1;
		shotRate = 2;
		price = 5;
	}
	if(type == blue){
		damage = 1;
		range = 3;
		shotRate = 2;
		price = 5;
	}
	setWidth(50);
	setHeight(50);
}
/* Destructor */
Tower::~Tower(){};

/****************************************
*************** DRAW ********************
*****************************************/
/* initialisation de la texture 
GLuint Tower::setTower() {
	GLuint textureID;
	if(type == red) {
		textureID = setTexture(filenameTower1);
		return textureID;
	}
	if(type == green) {
		textureID = setTexture(filenameTower2);
		return textureID;
	}
	if(type == yellow) {
		textureID = setTexture(filenameTower3);
		return textureID;
	}
	else{
		textureID = setTexture(filenameTower4);
		return textureID;
	}
}
*/
/* affichage de la texture 
void Tower::drawTower(GLuint textureID, float x, float y) {
	drawTexture(textureID, x, y);
}
*/

/****************************************
************** GET & SET ****************
*****************************************/
int Tower::getDamage() {
	int damage = this->damage;
	return damage;
}

int Tower::getRange() {
	int range = this->range;
	return range;
}

int Tower::getShotRate() {
	int shotRate = this->shotRate;
	return shotRate;
}

int Tower::getPrice() {
	int price = this->price;
	return price;
}

ColorType Tower::getColor() {
	ColorType type = this->type;
	return type;
}

void Tower::setDamage(int damage) {
	this->damage = damage;
}

void Tower::setRange(int range) {
	this->range = range;
}

void Tower::setShotRate(int shotRate) {
	this->shotRate = shotRate;
}

void Tower::setPrice(int price) {
	this->price = price;
}

void Tower::setColor(ColorType type) {
	this->type = type;
}		

//bool Tower::isBuildable(Position pos); /* vérifie si la tour peut etre construite a la position 'pos' */
//Position Tower::target(); /* renvoie la position de l'alien le plus proche */
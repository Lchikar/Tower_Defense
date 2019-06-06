#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "../include/Entity.hpp"
#include "../include/Alien.hpp"
#include "../include/Tower.hpp"

using namespace std;

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* Contructor */
Tower::Tower(ColorType type) {
	this->type = type;
	this->isClick = false;
	if(type == red){
		damage = 40;
		range = 50;
		shotRate = 1;
		price = 10;
	}
	if(type == green){
		damage = 20;
		range = 100;
		shotRate = 3;
		price = 10;
	}
	if(type == blue){
		damage = 5;
		range = 200;
		shotRate = 2;
		price = 10;
	}
	if(type == yellow){
		damage = 20;
		range = 100;
		shotRate = 2;
		price = 20;
	}
	setWidth(50);
	setHeight(50);
}
/* Destructor */
Tower::~Tower(){};

/****************************************
************* DRAW TOWER IHM ***********
*****************************************/
void Tower::drawTowerIHM(GLuint textureID) {
	float x = 530;
	float y;
	if(type == red) {
		y = 200;
	}
	if(type == green) {
		y = 115;
	}
	if(type == blue) {
		y = 30;
	}
	if(type == yellow) {
		y = -55;
	}
	this->setPos(Position(x, y));
	glPushMatrix();
	drawEntity(textureID);
	glPopMatrix();
}

/****************************************
***************** CLICK *****************
*****************************************/
void Tower::click(float mouseX, float mouseY) {
	if (this->getPos().dist(Position(mouseX, mouseY)) <= 25) {
		this->isClick = !this->isClick;
	}
} 

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

bool Tower::getIsClick() {
	bool isClick = this->isClick;
	return isClick;
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

void Tower::setIsClick(bool isClick){
	this->isClick = isClick;
}	

/****************************************
********** IS CONSTRUCTIBLE *************
*****************************************/
//vérifie si la tour peut etre construite a la position 'pos'
//bool Tower::isBuildable(Position pos); 


/****************************************
***************** TIR *******************
*****************************************/
//renvoie la position de l'alien le plus proche
Position Tower::target(vector<Alien> aliens){
	int dist_min = 9999999;
	Position target = this->getPos();
	for(Alien alien : aliens){
		int dist = alien.getPos().dist(this->getPos()); 
		if(dist <= this->range && dist < dist_min){
			dist_min = dist;
			target = alien.getPos();
		}
	}
	return target;
}

/* draw tir */
void Tower::drawShot(Position target) {
	glBegin(GL_LINES);
	glVertex2f(this->getPos().getX(),this->getPos().getY());
	glVertex2f(target.getX(),target.getY());
	glEnd();
}
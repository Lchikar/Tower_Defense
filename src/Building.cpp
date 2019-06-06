#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "../include/Entity.hpp"
#include "../include/Tower.hpp"
#include "../include/Building.hpp"

using namespace std;

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* Contructor */
Building::Building(TypeBuild type) {
	this->type = type;
	switch (type){
		case radar: this->value = 4;
			break;
		case navette: this->value = 300;
			break;
		case robot: this->value = 50;
			break;
	};
	this->isClick = false;
	this->price = 15;
	this->range = 500;
	setWidth(50);
	setHeight(50);
}
/* Destructor */
Building::~Building(){};


/****************************************
*********** DRAW BUILDING IHM ***********
*****************************************/
void Building::drawBuildingIHM(GLuint textureID) {
	float x = 530;
	float y;
	if(type == radar) {
		y = -140;
	}
	if(type == navette) {
		y = -225;
	}
	if(type == robot) {
		y = -310;
	}
	this->setPos(Position(x, y));
	glPushMatrix();
	drawEntity(textureID);
	glPopMatrix();
}

/****************************************
***************** CLICK *****************
*****************************************/
void Building::click(float mouseX, float mouseY) {
	if (this->getPos().dist(Position(mouseX, mouseY)) <= 25) {
		this->isClick = !this->isClick;
	}
} 

/****************************************
************** GET & SET ****************
*****************************************/
int Building::getValue() {
	int value = this->value;
	return value;
}

TypeBuild Building::getType() {
	TypeBuild type = this->type;
	return type;
}

bool Building::getIsClick() {
	bool isClick = this->isClick;
	return isClick;
}

int Building::getPrice(){
	int price = this->price;
	return price;
}

int Building::getRange(){
	int range = this->range;
	return range;
}

void Building::setIsClick(bool isClick){
	this->isClick = isClick;
}

/****************************************
**************** UPGRADE ****************
*****************************************/
//void Building::upgrade(Tower tower); /* améliore la tour 'tower' */
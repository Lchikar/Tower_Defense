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
	this->value = value;
	this->type = type;
	this->isClick = false;
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
	this->move(Position(x, y));
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
		printf("J'ai cliqué sur un batiment\n");
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

void Building::setValue(int value) {
	this->value = value;
}

void Building::setType(TypeBuild type) {
	this->type = type;
}

void Building::setIsClick(bool isClick){
	this->isClick = isClick;
}

//bool Building::isBuildable(Position pos); /* vérifie si le batiment peut etre construit a la position 'pos' */
//void Building::upgrade(Tower tower); /* améliore la tour 'tower' */
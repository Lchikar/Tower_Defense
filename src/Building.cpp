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
	setWidth(50);
	setHeight(50);
}
/* Destructor */
Building::~Building(){};

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

void Building::setValue(int value) {
	this->value = value;
}

void Building::setType(TypeBuild type) {
	this->type = type;
}


//bool Building::isBuildable(Position pos); /* vérifie si le batiment peut etre construit a la position 'pos' */
//void Building::upgrade(Tower tower); /* améliore la tour 'tower' */
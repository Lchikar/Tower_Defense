#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <cmath>

#include "../include/Position.hpp"
#include "../include/Entity.hpp"
#include "../include/texture.hpp"

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* Contructor */
Entity::Entity() {
	this->pos = Position();
}

Entity::Entity(Position pos, string sprite) {
	this->pos = pos;
	this->sprite = sprite;
}

/* Destructor */
Entity::~Entity(){};

/****************************************
*************** DRAW ********************
*****************************************/


/****************************************
************** GET & SET ****************
*****************************************/	
Position Entity::getPos() {
	Position pos = this->pos;
	return pos;
}

void Entity::setPos(Position p) {
	this->pos = p;
}

string Entity::getSprite() {
	string sprite = this->sprite;
	return sprite;
}

void Entity::setSprite(string sprite) {
	this->sprite = sprite;
}

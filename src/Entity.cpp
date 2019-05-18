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

Entity::Entity(Position pos, GLuint textureID) {
	this->pos = pos;
	this->textureID = textureID;
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

GLuint Entity::getTextureID() {
	GLuint textureID = this->textureID;
	return textureID;
}

void Entity::setTextureID(GLuint textureID) {
	this->textureID = textureID;
}

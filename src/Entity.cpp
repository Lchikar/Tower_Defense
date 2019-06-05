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

Entity::Entity(Position pos, GLuint textureID, float width, float height) {
	this->pos = pos;
	this->textureID = textureID;
	this->width = width;
	this->height = height;
}

/* Destructor */
Entity::~Entity(){};

/****************************************
*************** DRAW ********************
*****************************************/
void Entity::drawEntity(GLuint textureID) {
	glPushMatrix();
		glTranslatef(this->getPos().getX(), this->getPos().getY(), 0);
		drawTexture(textureID, width, height);
	glPopMatrix();
}

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

float Entity::getWidth() {
	float width = this->width;
	return width;
}

void Entity::setWidth(float width) {
	this->width = width;
}

float Entity::getHeight() {
	float height = this->height;
	return height;
}

void Entity::setHeight(float height) {
	this->height = height;
}

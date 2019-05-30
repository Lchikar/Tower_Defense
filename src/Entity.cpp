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

#include "../include/const.hpp"

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
void Entity::drawEntity(GLuint textureID, float x, float y) {
	glPushMatrix();
		glTranslatef(x, y, 0);
		this->move(Position(x, y));
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

void Entity::move(Position p) {
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

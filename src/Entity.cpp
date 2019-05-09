#include <iostream>
#include <string>
#include <cmath>


#include "../include/Position.hpp"
#include "../include/Entity.hpp"

Entity(Position pos, string sprite) {
	this->pos = pos;
	this->sprite = sprite;
}

		
Position getPos() {
	Position pos = this->pos;
	return pos;
}

void setPos(Position p) {
	this->pos = p;
}

string getSprite() {
	string sprite = this->sprite;
	return sprite;
}

void setSprite(string sprite) {
	this->sprite = sprite;
}

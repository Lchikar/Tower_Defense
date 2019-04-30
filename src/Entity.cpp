#include <iostream>
#include <string>

#include "Position.hpp"
#include "Entity.hpp"

Entity(Position p, string sprite) {
	pos = p;
	sprite = sprite;
}

~Entity();
		
Position getPos() {
	Position pos = this.pos;
	return pos;
}

void setPos(Position p) {
	this.pos = p;
}

string getSprite() {
	string sprite = this.sprite;
	return sprite;
}

void setSprite(string sprite) {
	this.sprite = sprite;
}

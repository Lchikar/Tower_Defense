#include <iostream>
#include <string>

#include "Position.hpp"
#include "Entity.hpp"

Entity(Position p, string sprt) {
	pos = p;
	sprite = sprt;
}
		
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

#include <iostream>
#include <string>

#include "Position.hpp"

Position(float x, float y) {
	this->x = x;
	this->y = y;
}

float getX() {
	float x = this->x;
	return x;
}

float getY() {
	float y = this->y;
	return y;
}

void setX(float x) {
	this->x = x;
}

void setY(float Y) {
	this->y = y;
}

int dist(Position p);

#include <iostream>
#include <string>
#include <cmath>

#include "../include/Position.hpp"

Position::Position() {
	x = 0;
	y = 0;
}

Position::Position(float x, float y) {
	this->x = x;
	this->y = y;
}

float Position::getX() {
	float x = this->x;
	return x;
}

float Position::getY() {
	float y = this->y;
	return y;
}

void Position::setX(float x) {
	this->x = x;
}

void Position::setY(float y) {
	this->y = y;
}

int Position::dist(Position p){
	printf("calcul de sqrt((pow%d-%d,2)+(pow(%d-%d,2))\n", this->x, p.getX(), this->y, p.getY());
	return sqrt(
		(pow(this->x-p.getX(), 2))+
		(pow(this->y-p.getY(), 2))
		);
			
}
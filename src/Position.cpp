#include <iostream>
#include <string>

#include "../include/Position.hpp"

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

void Position::setY(float Y) {
	this->y = y;
}

int Position::dist(Position p){
	return sqrt(pow(this->getX()-p.getX(), 2)+pow(this->getY()-p.getY(), 2));
}
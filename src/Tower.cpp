#include <iostream>
#include <string>

#include "../include/Entity.hpp"
#include "../include/Tower.hpp"

Tower::Tower(ColorType color) {
	if(color == red){
		damage = 3;
		range = 2;
		shotRate = 1;
		price = 5;
	}
	if(color == green){
		damage = 2;
		range = 1;
		shotRate = 3;
		price = 5;
	}
	if(color == yellow){
		damage = 1;
		range = 1;
		shotRate = 2;
		price = 5;
	}
	if(color == blue){
		damage = 1;
		range = 3;
		shotRate = 2;
		price = 5;
	}
}

int Tower::getDamage() {
	int damage = this->damage;
	return damage;
}

int Tower::getRange() {
	int range = this->range;
	return range;
}

int Tower::getShotRate() {
	int shotRate = this->shotRate;
	return shotRate;
}

int Tower::getPrice() {
	int price = this->price;
	return price;
}

ColorType Tower::getColor() {
	ColorType color = this->color;
	return color;
}

void Tower::setDamage(int damage) {
	this->damage = damage;
}

void Tower::setRange(int range) {
	this->range = range;
}

void Tower::setShotRate(int shotRate) {
	this->shotRate = shotRate;
}

void Tower::setPrice(int price) {
	this->price = price;
}

void Tower::setColor(ColorType color) {
	this->color = color;
}		

//bool Tower::isBuildable(Position pos); /* vérifie si la tour peut etre construite a la position 'pos' */
//Position Tower::target(); /* renvoie la position de l'alien le plus proche */
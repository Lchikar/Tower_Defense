#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Tower.hpp"

Tower(ColorType color) {
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

int getDamage() {
	int damage = this->damage;
	return damage;
}

int getRange() {
	int range = this->range;
	return range;
}

int getShotRate() {
	int shotRate = this->shotRate;
	return shotRate;
}

int getPrice() {
	int price = this->price;
	return price;
}

ColorType getColor() {
	ColorType color = this->color;
	return color;
}

void setDamage(int damage) {
	this->damage = damage;
}

void setRange(int range) {
	this->range = range;
}

void setShotRate(int shotRate) {
	this->shotRate = shotRate;
}

void setPrice(int price) {
	this->price = price;
}

void setColor(ColorType color) {
	this->color = color;
}		

bool isBuildable(Position pos); /* vérifie si la tour peut etre construite a la position 'pos' */
Position target(); /* renvoie la position de l'alien le plus proche */
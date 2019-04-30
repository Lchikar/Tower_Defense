#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Tower.hpp"

Tower();

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

string getColor() {
	string color = this->color;
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

void setColor(string color) {
	this->color = color;
}		

bool isBuildable(Position pos); /* vérifie si la tour peut etre construite a la position 'pos' */
Position target(); /* renvoie la position de l'alien le plus proche */
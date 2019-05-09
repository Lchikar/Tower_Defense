#include <iostream>
#include <string>

#include "../include/Entity.hpp"
#include "../include/Tower.hpp"
#include "../include/Building.hpp"

Building(int value, TypeBuild type) {
	this->value = value;
	this->type = type;
}

int getValue() {
	int value = this->value;
	return value;
}

TypeBuild getType() {
	TypeBuild type = this->type;
	return type;
}

void setValue(int value) {
	this->value = value;
}

void setType(TypeBuild type) {
	this->type = type;
}


bool isBuildable(Position pos); /* vérifie si le batiment peut etre construit a la position 'pos' */
void upgrade(Tower* tower); /* améliore la tour 'tower' */
#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Tower.hpp"
#include "Building.hpp"

Building(TypeBuild type);

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
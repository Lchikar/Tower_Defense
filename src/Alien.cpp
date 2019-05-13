#include <iostream>
#include <string>

#include "../include/Entity.hpp"
#include "../include/Tower.hpp"
#include "../include/Path.hpp"
#include "../include/Alien.hpp"

Alien::Alien(AlienType type){
	if(type == fatty){
		pv =  150;
		reward = 100;
		speed = 20;
	}
	else{
		pv =  50;
		reward = 50;
		speed = 100;
	}
}


int Alien::getPv(){
	int pv = this->pv;
	return pv;
}

int Alien::getReward() {
	int reward = this->reward;
	return reward;
}

int Alien::getSpeed() {
	int speed = this->speed;
	return speed;
}

void Alien::setPv(int pv){
	this->pv = pv;
}

void Alien::setReward(int reward) {
	this->reward = reward;
}

void Alien::setSpeed(int speed) {
	this->speed = speed;
}

//Path Alien::choosePath(); /* choisit un chemin à suivre selon le risque */
//int Alien::resistance(string towerColor); /* calcule la resistance aux attaques de la tour 'tower' */
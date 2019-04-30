#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Tower.hpp"
#include "Path.hpp"
#include "Alien.hpp"

Alien(AlienType type){
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


~Alien();

int getPv(){
	int pv = this.pv;
	return pv;
}

int getReward() {
	int reward = this.reward;
	return reward;
}

int getSpeed() {
	in speed = this.speed;
	return speed;
}

void setPv(int pv){
	this.pv = pv;
}

void setReward(int reward) {
	this.reward = reward;
}

void setSpeed(int speed) {
	this.speed = speed;
}

Path choosePath(); /* choisit un chemin à suivre selon le risque */
int resistance(string towerColor); /* calcule la resistance aux attaques de la tour 'tower' */
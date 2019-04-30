#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Tower.hpp"
#include "Path.hpp"
#include "Alien.hpp"

Alien(AlienType type){
	Alien alien = new Alien();
	if(type == fatty){
		alien.pv =  150;
		alien.reward = 100;
		alien.speed = 20;
	}
	else{
		alien.pv =  50;
		alien.reward = 50;
		alien.speed = 100;
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
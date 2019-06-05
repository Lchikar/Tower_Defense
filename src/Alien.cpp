#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "../include/Entity.hpp"
#include "../include/Graph.hpp"
#include "../include/Alien.hpp"

using namespace std;

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* Contructor */
Alien::Alien(AlienType type, Graph G, Position pos){
	this->type = type;
	this->setPos(pos);
	if(type == fatty){
		this->damage =	20;
		pv =  150;
		reward = 100;
		speed = 10;
	} else {
		this->damage = 10;
		pv =  50;
		reward = 50;
		speed = 20;
	}
	setWidth(35);
	setHeight(35);
	map<int,vector<pair<int,int>>> paths = G.Dijkstra(0); 
	this->path = paths[paths.size()-1];
}
/* Destructor */
Alien::~Alien(){};


/****************************************
************** GET & SET ****************
*****************************************/
int Alien::getPv() {
	int pv = this->pv;
	return pv;
}

int Alien::getDamage(){
	return this->damage;
}

int Alien::getReward() {
	int reward = this->reward;
	return reward;
}

int Alien::getSpeed() {
	int speed = this->speed;
	return speed;
}

AlienType Alien::getAlienType() {
	AlienType type = this->type;
	return type;
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

void Alien::setAlienType(AlienType type) {
	this->type = type;
}

vector<pair<int,int>> Alien::getPath(){
	return this->path;
}

pair<int,int>* Alien::getNextStep(int i){
	if(vector<pair<int,int>>() == this->path)
		return NULL;
	return &(this->path[i]);
}


/****************************************
***************** PATH ******************
*****************************************/
void Alien::updatePath(Graph G){
	if(this->path.size() == 1){
		this->path.push_back(pair<int,int>(this->path[0].second, this->path[0].second));
	}
    this->path.erase(this->path.begin(), this->path.begin()+1);
	// printf("après pop first path : ");
 //    for(int j = 0; j < this->path.size(); j++)
 //        printf("(%d,%d) ", this->path[j].first, this->path[j].second);
 //    printf("\n");
}

int Alien::dest(){
	return this->path[0].first;
}
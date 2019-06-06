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
		pv =  150;
		reward = 10;
		speed = 5;
	} else {
		pv =  50;
		reward = 5;
		speed = 10;
	}
	setWidth(35);
	setHeight(35);
	map<int,vector<pair<int,int>>> paths = G.Dijkstra(0);
	for(auto i = paths.begin(); i != paths.end(); i++){
   		printf("TO %d : ", i->first);
   		for(auto j = i->second.begin(); j != i->second.end(); j++)
	   		printf("(%d,%d) ", j->first, 
	   			j->second);
	   	printf("\n");
   	}
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
void Alien::updatePath(){
	if(this->path.size() == 1){
		this->path.push_back(pair<int,int>(this->path[0].second, this->path[0].second));
	}
    this->path.erase(this->path.begin(), this->path.begin()+1);
}

void Alien::newPath(Graph G){
	int src = this->dest();
	// printf("SRC %d\n", src);
    map<int,vector<pair<int,int>>> paths = G.Dijkstra(this->dest());
	
	int nbchemins = 0;
	for(auto i = paths.begin(); i != paths.end(); i++)
		nbchemins++;

	printf("%d chemins depuis %d\n", nbchemins, src);
	
   	for(auto i = paths.begin(); i != paths.end(); i++){
   		printf("TO %d : ", i->first);
   		for(auto j = i->second.begin(); j != i->second.end(); j++)
	   		printf("(%d,%d) ", j->first, 
	   			j->second);
	   	printf("\n");
   	}

   	this->path = paths[11];
	
	// for(int j = 0; j < this->getPath().size(); j++){
 //        printf("(%d,%d) ", this->getNextStep(j)->first, this->getNextStep(j)->second);
 //    }
}

int Alien::dest(){
	return this->path[0].first;
}
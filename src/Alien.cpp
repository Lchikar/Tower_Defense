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
		reward = 100;
		speed = 10;
	} else {
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

void Alien::move(Alien* alien, Position p){
	printf("Move alien %p\n", this);
	this->setPos(p);
	printf("new pos (%f,%f)\n", this->getPos().getX(),this->getPos().getY());
}

/****************************************
*************** DRAW ********************
*****************************************/
/*
//initialisation de la texture
GLuint Alien::setAlien() {
	GLuint textureID;
	if(type == fatty) {
		textureID = setTexture(filenameFatty);
		return textureID;
	} 
	else{
		textureID = setTexture(filenameNervous);
		return textureID;
	}
}
*/
/* affichage de la texture 
void Alien::drawAlien(GLuint textureID) {
	drawTexture(textureID, 35, 35);
}
*/



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

void Alien::updatePath(Graph G){
    this->path.erase(this->path.begin());
    map<int,vector<pair<int,int>>> new_paths = G.Dijkstra(this->path[0].first); 
	this->path = new_paths[new_paths.size()-1];
}

int Alien::dest(){
	return this->path[0].second;
}
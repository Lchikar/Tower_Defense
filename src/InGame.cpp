#include <iostream> 
#include <algorithm>
#include <vector> 

#include "../include/Alien.hpp"
#include "../include/Tower.hpp"
#include "../include/Building.hpp"
#include "../include/InGame.hpp"
#include "../include/Graph.hpp"

InGame::InGame(Graph G, Position pos_init_aliens){
	this->life = 100;
	this->money = 150;
	this->waves = 1;

	this->towers = vector<Tower>();
	this->buildings = vector<Building>();
	this->aliens = vector<Alien>();

	this->aliens.push_back(Alien(fatty, G, pos_init_aliens));
	this->aliens.push_back(Alien(fatty, G, pos_init_aliens));
	this->aliens.push_back(Alien(nervous, G, pos_init_aliens));
	this->aliens.push_back(Alien(nervous, G, pos_init_aliens));
}

InGame::~InGame(){;}

vector<Alien> InGame::getAliens(){
	return this->aliens;
}
Alien* InGame::getAlien(int i){
	return &(this->aliens[i]); 
}

vector<Tower> InGame::getTowers(){
	return this->towers;
}
vector<Building> InGame::getBuildings(){
	return this->buildings;
}

//we can change the tables entirely for each wave
//or add/delete an entity to it
void InGame::reinitAliens(){
	this->aliens = vector<Alien>();
}
void InGame::reinitTowers(){
	this->towers = vector<Tower>();
}
void InGame::reinitBuildings(){
	this->buildings = vector<Building>();
}

void InGame::addAliens(Alien alien){
	this->aliens.push_back(alien);
}
void InGame::addTowers(ColorType type, Position p){
	Tower tower = Tower(type);
	tower.setPos(p);
	this->towers.push_back(tower);
}
void InGame::addBuildings(TypeBuild type, Position p){
	Building building = Building(type);
	building.setPos(p);
	this->buildings.push_back(building);
}

void InGame::deleteAliens(int alien_index){
	if(this->aliens.size() <= alien_index){
		fprintf(stderr, "Cannot erase non-existent alien\n");
		return;
	}
	this->aliens.erase(this->aliens.begin()+alien_index, this->aliens.begin()+alien_index+1);
}

int InGame::getLife(){
	return this->life;
}
//in this version you can't be healed
void InGame::setLife(int pv){
	this->life -= pv;
}


int InGame::getMoney(){
	return this->money;
}
//positive price if from monster
//negative price if from shop
void InGame::setMoney(int price){
	this->money += price;
}

int InGame::getWaves(){
	return this->waves;
}
//number waves increases always
void InGame::updateWaves(){
	this->waves++;
}
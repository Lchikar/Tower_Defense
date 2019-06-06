#include <iostream> 
#include <algorithm>
#include <vector> 

#include "../include/Alien.hpp"
#include "../include/Tower.hpp"
#include "../include/Building.hpp"
#include "../include/InGame.hpp"
#include "../include/Graph.hpp"

InGame::InGame(Graph G, Position pos_init_aliens){
	this->money = 50;
	this->waves = 1;

	this->towers = vector<Tower>();
	this->buildings = vector<Building>();
	this->aliens = vector<Alien>();

	for(int i = 0; i < 5; i++){
		this->aliens.push_back(Alien(fatty, G, pos_init_aliens));
		this->aliens.push_back(Alien(nervous, G, pos_init_aliens));
	}
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

Tower* InGame::getTower(int i){
	return &(this->towers[i]);
}
vector<Building> InGame::getBuildings(){
	return this->buildings;
}

//we can change the tables entirely for each wave
//or add/delete an entity to it
void InGame::initAliens(vector<vector<int>> nodes, Graph G){
	this->aliens.clear();
	Position pos_init_aliens = Position(float(nodes[0][1]),float(nodes[0][2]));		
	for(int i = 0; i < 10; i++){
		if(0 == i%2)
			this->aliens.push_back(Alien(fatty, G, pos_init_aliens));
		else
			this->aliens.push_back(Alien(nervous, G, pos_init_aliens));
        
        this->aliens[i].setPos(Position(float(nodes[this->aliens[i].getNextStep(0)->first][1])-((rand()%10*i+20*i)*(i%5)),
        	float(nodes[this->aliens[i].getNextStep(0)->first][2])));
    }	
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
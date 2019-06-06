#pragma once

#include <iostream> 
#include <algorithm>
#include <vector> 

#include "Alien.hpp"
#include "Tower.hpp"
#include "Building.hpp"
#include "Graph.hpp"

using namespace std;

class InGame{
	private:
		vector<Alien> aliens;
		vector<Tower> towers;
		vector<Building> buildings;
		int money;
		int waves;

	public:
		InGame(Graph G, Position pos_init_aliens);
		~InGame();

		vector<Alien> getAliens();
		Alien* getAlien(int i);
		void initAliens(vector<vector<int>> nodes, Graph G);
		void addAliens(Alien aliens);
		void deleteAliens(int alien_index);

		vector<Tower> getTowers();
		Tower* getTower(int i);
		void addTowers(ColorType type, Position p);
		//towers can't be deleted
		
		vector<Building> getBuildings();
		void addBuildings(TypeBuild type, Position p);
		//buildings can't be deleted

		int getMoney();
		void setMoney(int price);

		int getWaves();
		void updateWaves();
		
};
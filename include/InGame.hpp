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
		int life;
		int money;
		int waves;

	public:
		InGame(Graph G, Position pos_init_aliens);
		~InGame();

		vector<Alien> getAliens();
		void reinitAliens();
		void addAliens(Alien aliens);
		void deleteAliens(int alien_index);

		vector<Tower> getTowers();
		void reinitTowers();
		void addTowers(ColorType type, Position p);
		//towers can't be deleted
		
		vector<Building> getBuildings();
		void reinitBuildings();
		void addBuildings(TypeBuild type, Position p);
		//buildings can't be deleted

		int getLife();
		void setLife(int pv);

		clock_t getTime();
		void updateTime();

		int getMoney();
		void setMoney(int price);

		int getWaves();
		void updateWaves();
		
};
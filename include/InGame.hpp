#pragma once

#include <iostream> 
#include <algorithm>
#include <vector> 
#include <ctime>

#include "Alien.hpp"
#include "Tower.hpp"
#include "Building.hpp"

using namespace std;

class InGame{
	private:
		vector<Alien> aliens;
		vector<Tower> towers;
		vector<Building> buildings;
		int life;
		clock_t time;
		int money;
		int waves;

	public:
		InGame();
		~InGame();

		vector<Alien> getAliens();
		void reinitAliens();
		void addAliens(Alien aliens);
		void deleteAliens(int alien_index);

		vector<Tower> getTowers();
		void reinitTowers();
		void addTowers(Tower towers);
		//towers can't be deleted
		
		vector<Building> getBuildings();
		void reinitBuildings();
		void addBuildings(Building buildings);
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
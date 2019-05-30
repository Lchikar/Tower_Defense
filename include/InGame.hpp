#pragma once

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
		void setAliens(vector<Alien> aliens);

		vector<Tower> getTowers();
		void setTowers(vector<Tower> towers);
		
		vector<Building> getBuildings();
		void setBuildings(vector<Building> buildings);

		int getLife();
		void setLife(int pv);

		clock_t getTime();
		void setTime(clock_t time);

		int getMoney();
		void setMoney(int price);

		int getWaves();
		void setWaves(int wave);

		
}
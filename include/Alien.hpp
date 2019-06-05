#pragma once
 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Graph.hpp"

using namespace std;

enum AlienType
{
	fatty,
	nervous,
};


class Alien : public Entity {
	private :
		int pv; /* points de vie */
		int reward; /* argent laisse apres la mort */
		int speed; /* vitesse de deplacement en unite de temps */
		AlienType type; /* type d'alien */
		vector<pair<int,int>> path; //chemin jusqu'à la sortie

	public:
		Alien(AlienType type, Graph G, Position pos);
		~Alien();

		/* get & set*/
		int getPv();
		int getReward();
		int getSpeed();
		AlienType getAlienType();
		vector<pair<int,int>> getPath();
		pair<int,int>* getNextStep(int i);
		
		void setPv(int pv);
		void setReward(int reward);
		void setSpeed(int speed);
		void setAlienType(AlienType type);
		
		/* path */
		void updatePath(Graph G);
		int dest();



};

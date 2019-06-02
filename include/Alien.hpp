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

		/* initialisation de la texture */
		//GLuint setAlien();

		/* affichage de la texture */
		//void drawAlien(GLuint textureID);

		/* get */
		int getPv();
		int getReward();
		int getSpeed();
		AlienType getAlienType();
		vector<pair<int,int>> getPath();

		/* set */
		void setPv(int pv);
		void setReward(int reward);
		void setSpeed(int speed);
		void setAlienType(AlienType type);
		void updatePath(Graph G);
		int dest();
		void move(Alien* alien, Position p);



};

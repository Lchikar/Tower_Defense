#ifndef DEF_ALIEN
#define DEF_ALIEN
 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Tower.hpp"
#include "Path.hpp"
#include "texture.hpp"

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

	public:
		Alien(AlienType type);
		~Alien();

		/* initialisation de la texture */
		GLuint setAlien();

		/* affichage de la texture */
		void drawAlien(GLuint textureID, float x, float y);

		/* get */
		int getPv();
		int getReward();
		int getSpeed();

		/* set */
		void setPv(int pv);
		void setReward(int reward);
		void setSpeed(int speed);

		//Path choosePath(); /* choisit un chemin à suivre selon le risque */
		//int resistance(string towerColor); /* calcule la resistance aux attaques de la tour 'tower' */
};

#endif

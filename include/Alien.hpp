#ifndef DEF_ALIEN
#define DEF_ALIEN
 
#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Tower.hpp"
#include "Path.hpp"

enum AlienType
{
	fatty;
	nervous;
};


class Alien : public Entity{
	private :
		int pv; /* points de vie */
		int reward; /* argent laisse apres la mort */
		int speed; /* vitesse de deplacement en unite de temps */
		AlienType type; /* type d'alien */

	public:
		Alien(AlienType type);
		~Alien();

		int getPv();
		int getReward();
		int getSpeed();

		void setPv(int pv);
		void setReward(int reward);
		void setSpeed(int speed);

		Path choosePath(); /* choisit un chemin à suivre selon le risque */
		int resistance(string towerColor); /* calcule la resistance aux attaques de la tour 'tower' */
};

#endif

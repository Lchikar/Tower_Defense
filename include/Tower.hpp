#ifndef DEF_TOWER
#define DEF_TOWER
 
#include <iostream>
#include <string>

#include "Entity.hpp"


class Tower : public Entity{
	private :
		int damage; /* degats */
		int range; /* portee */
		int shotRate; /* cadence de tir */
		int price; /* prix */
		string color; /* couleur de la tour */

	public:
		Tower();
		~Tower();

		int getDamage();
		int getRange();
		int getShotRate();
		int getPrice();
		string getColor();

		void setDamage(int damage);
		void setRange(int range);
		void setShotRate(int shotRate);
		void setPrice(int price);
		void setColor(string color);		

		bool isBuildable(Position pos); /* vérifie si la tour peut etre construite a la position 'pos' */
		Position target(); /* renvoie la position de l'alien le plus proche */
};

#endif

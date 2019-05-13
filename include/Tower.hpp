#ifndef DEF_TOWER
#define DEF_TOWER
 
#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Position.hpp"

enum ColorType
{
	red,
	green,
	yellow,
	blue,
};

class Tower : public Entity {
	private :
		int damage; /* degats */
		int range; /* portee */
		int shotRate; /* cadence de tir */
		int price; /* prix */
		ColorType color; /* couleur de la tour */

	public:
		Tower(ColorType color);
		~Tower();

		int getDamage();
		int getRange();
		int getShotRate();
		int getPrice();
		ColorType getColor();

		void setDamage(int damage);
		void setRange(int range);
		void setShotRate(int shotRate);
		void setPrice(int price);
		void setColor(ColorType color);		

		//bool isBuildable(Position pos); /* vérifie si la tour peut etre construite a la position 'pos' */
		//Position target(); /* renvoie la position de l'alien le plus proche */
};

#endif

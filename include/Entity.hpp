#ifndef DEF_ENTITY
#define DEF_ENTITY
 
#include <iostream>
#include <string>
#include "Position.hpp"

using namespace std;


class Entity{

	private:
		Position pos; /* position de l'entite */
		string sprite; /* nom de la forme representant l'entite <==> 'GL_forme' */

	public:
		Entity();
		Entity(Position pos, string sprite);
		~Entity();
		
		Position getPos();
		void setPos(Position p);

		string getSprite();
		void setSprite(string sprite);
};

#endif
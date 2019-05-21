#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Tower.hpp"

using namespace std;

enum TypeBuild
{
	radar,
	navette,
	robot,
};

class Building : public Entity{
	private :
		int value; /* valeur de l'upgrade */
		TypeBuild type; /* type d'upgrade */

	public:
		Building(TypeBuild type);
		~Building();

		int getValue();
		TypeBuild getType();

		void setValue(int value);
		void setType(TypeBuild type);


		//bool isBuildable(Position pos); /* vérifie si le batiment peut etre construit a la position 'pos' */
		//void upgrade(Tower tower); /* améliore la tour 'tower' */
};

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
		bool isClick;
		int price;

	public:
		Building(TypeBuild type);
		~Building();

		/* Affichage des bâtiments déjà présents sur l'interface */
		void drawBuildingIHM(GLuint textureID);

		/* is click */
		void click(float mouseX, float mouseY);

		/* get & set */
		int getValue();
		TypeBuild getType();
		bool getIsClick();
		int getPrice();

		void setValue(int value);
		void setType(TypeBuild type);
		void setIsClick(bool isClick);

		//void upgrade(Tower tower); /* améliore la tour 'tower' */
};

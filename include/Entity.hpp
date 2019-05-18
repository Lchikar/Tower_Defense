#ifndef DEF_ENTITY
#define DEF_ENTITY

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <cmath>

#include "Position.hpp"
#include "texture.hpp"

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
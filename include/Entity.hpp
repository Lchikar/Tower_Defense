#pragma once

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
		GLuint textureID; /* nom de la forme representant l'entite <==> 'GL_forme' */

	public:
		Entity();
		Entity(Position pos, GLuint textureID);
		~Entity();
		
		Position getPos();
		void setPos(Position p);

		GLuint getTextureID();
		void setTextureID(GLuint textureID);
};
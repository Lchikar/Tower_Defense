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

#include "const.hpp"

using namespace std;


class Entity {

	private:
		Position pos; /* position de l'entite */
		GLuint textureID; /* nom de la forme representant l'entite <==> 'GL_forme' */
		float width;
		float height;

	public:
		Entity();
		Entity(Position pos, GLuint textureID, float width, float height);
		~Entity();

		void drawEntity(GLuint textureID, float x, float y);
		
		Position getPos();
		//set position
		void move(Position p);

		GLuint getTextureID();
		void setTextureID(GLuint textureID);

		float getWidth();
		void setWidth(float width);

		float getHeight();
		void setHeight(float height);

};
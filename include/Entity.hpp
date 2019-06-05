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


class Entity {

	private:
		Position pos; /* position de l'entite */
		float width;
		float height;

	public:
		Entity();
		Entity(Position pos, float width, float height);
		~Entity();

		void drawEntity(GLuint textureID);
		
		Position getPos();
		//set position
		void setPos(Position p);

		float getWidth();
		void setWidth(float width);

		float getHeight();
		void setHeight(float height);

};
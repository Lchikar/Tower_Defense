#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "texture.hpp"

using namespace std;

class Map {
	
	private:
		
	public:
		Map();
		~Map();

		/* initialisation de la texture */
		GLuint setMap();

		/* affichage de la texture */
		void drawMap(GLuint textureID, float x, float y);
};
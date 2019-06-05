#pragma once
 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "texture.hpp"

using namespace std;

enum IHMType
{
	coins,
	interface,
	userGuide,
	winner,
	gameover
};

class IHM {
	private :
		IHMType type;

	public:
		IHM();
		IHM(IHMType type);
		~IHM();

		GLuint setIHMTexture();
		void drawIHM(GLuint textureID);
};



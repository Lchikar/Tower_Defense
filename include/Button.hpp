#pragma once
 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "Entity.hpp"
#include "texture.hpp"

using namespace std;

enum ButtonType
{
	info,
	play,
	pause,
	cros,
};

class Button : public Entity {
	private :
		ButtonType type;

	public:
		Button();
		Button(ButtonType type);
		~Button();

		GLuint setButtonTexture();
		void drawButton(GLuint textureID);

};


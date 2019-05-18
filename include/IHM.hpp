#ifndef DEF_IMH
#define DEF_IHM
 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "texture.hpp"

using namespace std;


class IHM{
	private :


	public:
		IHM();
		~IHM();

		GLuint setButtonInfo();

		void setIHM();
		void drawIHM();
		void deleteIHM();

};

#endif

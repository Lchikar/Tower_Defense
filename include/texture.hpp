#ifndef DEF_TEXTURE
#define DEF_TEXTURE

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

int isLoaded (SDL_Surface* image);

GLuint setTexture(const char* filename);

void drawTexture(GLuint textureID, float x, float y);

#endif
#pragma once

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

int isLoaded (SDL_Surface* image);

// Initialise la texture avec le fichier
GLuint setTexture(const char* filename);

// Affiche la texture
void drawTexture(GLuint textureID, float x, float y);

// Afficher une chaîne de caratère
void vBitmapOutput(int x, int y, char *string, void *font);
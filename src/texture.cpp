#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../include/texture.hpp"

using namespace std;

int isLoaded (SDL_Surface* image) {
    if (image == NULL) {
        printf("Texture loading failed\n");
        SDL_Quit();
        return 0;
    }
    return 1;
}

GLuint setTexture(const char* filename) {
	// Chargement et traitement de la texture
    SDL_Surface *image = IMG_Load(filename);
    if (!isLoaded(image)) return 0;

    GLuint textureID;

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 
    // Envoie des données texture à la carte graphique
    glTexImage2D(
        GL_TEXTURE_2D, 
        0, 
        GL_RGBA, 
        image->w, 
        image->h, 
        0, 
        GL_RGBA, 
        GL_UNSIGNED_BYTE, 
        image->pixels);

    // Libération des données CPU
    glBindTexture(GL_TEXTURE_2D, 0);
    SDL_FreeSurface(image);

    return textureID;
}

void drawTexture(GLuint textureID, float x, float y) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        	glBegin(GL_QUADS);
        		glTexCoord2f(0,1);
        		glVertex2f(-x/2, -y/2);
        		glTexCoord2f(1,1);
        		glVertex2f(x/2, -y/2);
        		glTexCoord2f(1,0);
        		glVertex2f(x/2, y/2);
        		glTexCoord2f(0,0);
        		glVertex2f(-x/2, y/2);
        	glEnd();
		glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
}
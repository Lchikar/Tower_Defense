#ifndef DEF_MAP
#define DEF_MAP


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "texture.hpp"

using namespace std;

enum TileType {empty, path, tower, alien};

class Map {
	
	private:
		// grille decrivant la map et ce qu'elle contient a chaque case
		//std::vector<TileType> grid;
	public:
		Map();
		~Map(); /* penser aux delete */

		/* Verifier itd*/
		bool checkITD();

		GLuint setMap();
		void drawMap(GLuint textureID, float x, float y);

		//TileType getTileType();
};

#endif
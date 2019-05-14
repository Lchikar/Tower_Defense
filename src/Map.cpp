#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <fstream>

#include "../include/Map.hpp"
#include "../include/texture.hpp"

using namespace std;

const char* filenameMap = "./img/assets/textMapMars.png";

/****************************************
************ CONSTRUCTOR ****************
*****************************************/
/* contructor */
Map::Map(){};

/* destructor */
Map::~Map(){};


/****************************************
************* CHECK ITD *****************
*****************************************/
/* verification de la validité du .itd */
// en cours
bool Map::checkITD() {
	// ouvrir .itd
	string const mapName("./data/testmap.itd");
	ifstream map(mapName.c_str());

	if(map) {

		int entier1;
		string chaine1;

		map.seekg(0, ios::beg);
		map>>chaine1;
		if(chaine1!="@ITD") {return EXIT_FAILURE;}

		map.seekg(1, ios::cur);
		map>>entier1;
		if(!entier1) {return EXIT_FAILURE;}

		map.seekg(1, ios::cur);
		map>>chaine1;
		if(chaine1!="#") {return EXIT_FAILURE;}
	
	}
	return true;
}


/****************************************
*************** DRAW ********************
*****************************************/
/* initialisation de la texture */
GLuint Map::setMap() {
	GLuint textureID = setTexture(filenameMap); 
	return textureID;
}

/* affichage de la texture */
void Map::drawMap(GLuint textureID, float x, float y){
	drawTexture(textureID, x, y);
}
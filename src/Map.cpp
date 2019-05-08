#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool Map::checkITD() {
	// ouvrir .itd
	string const mapName("./data/testmap.itd");
	ifstream map(mapName.c_str());

	if(map) {

		int entier1;
		string chaine1;

		map.seekg(0, ios::beg);
		map>>chaine1;
		if(chaine1!="@ITD") {return EXIT_FAILURE};

		map.seekg(1, ios::cur);
		map>>entier1;
		if(!entier1) {return EXIT_FAILURE};

		map.seekg(1, ios::cur);
		map>>chaine1;
		if(chaine1!="#") {return EXIT_FAILURE};


		return true;
	}
}
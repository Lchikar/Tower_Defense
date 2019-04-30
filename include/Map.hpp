#ifndef DEF_MAP
#define DEF_MAP
 
#include <iostream>
#include <string>

enum TileType {empty, path, tower, alien};

class Map{
	
	private:
		// grille decrivant la map et ce qu'elle contient a chaque case
		std::vector<TileType> grid;
	public:
		Map();
		~Map(); /* penser aux delete */

		void draw();

		TileType getTileType();
};

#endif
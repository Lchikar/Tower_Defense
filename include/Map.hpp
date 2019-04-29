#ifndef DEF_MAP
#define DEF_MAP
 
#include <iostream>
#include <string>

typedef enum {empty=0, path=1, tower=2, alien=3} TileType;

class Map{
	
	private:
		// grille decrivant la map et ce qu'elle contient a chaque case
		std::vector<TileType> grid;
	public:
		Map();
		~Map(); /* penser aux delete */

		void draw();

		TileType getTileType();

#endif
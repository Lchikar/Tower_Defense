#ifndef DEF_POSITION
#define DEF_POSITION
 
#include <iostream>
#include <string>

class Position{
	
	private:
		float x;
		float y;

	public:
		Position();
		~Position(); /* penser aux delete */

		int dist(Position p); /* calcule la distance entre this et p */
}

#endif
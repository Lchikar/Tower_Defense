#ifndef DEF_POSITION
#define DEF_POSITION
 
#include <iostream>
#include <string>
#include <cmath>


class Position {
	
	private:
		float x;
		float y;

	public:
		Position();
		Position(float x, float y);
		~Position(){};
		
		float getX();
		float getY();

		void setX(float x);
		void setY(float Y);

		int dist(Position p); /* calcule la distance entre this et p */
};

#endif
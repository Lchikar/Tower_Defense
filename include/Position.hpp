#pragma once

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

		//calcule la distance entre this et p
		float dist(Position p); 

		//prduit scalaire
		float scalaire(Position p);
		//produit vectoriel
		float vectoriel(Position p);
};
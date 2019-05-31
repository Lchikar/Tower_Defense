#pragma once

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Alien.hpp"

using namespace std;

enum ColorType
{
	red,
	green,
	blue,
	yellow,
};

class Tower : public Entity {
	private :
		int damage; /* degats */
		int range; /* portee */
		int shotRate; /* cadence de tir */
		int price; /* prix */
		ColorType type; /* couleur de la tour */
		bool isClick;

	public:
		Tower(ColorType type);
		~Tower();

		/* initialisation de la texture */
		//GLuint setTower();

		/* DRAW TOWER IHM */
		void drawTowerIHM(GLuint textureID);

		/* is click */
		void click(float mouseX, float mouseY);

		/* get */
		int getDamage();
		int getRange();
		int getShotRate();
		int getPrice();
		ColorType getColor();
		bool getIsClick();

		/* set */
		void setDamage(int damage);
		void setRange(int range);
		void setShotRate(int shotRate);
		void setPrice(int price);
		void setColor(ColorType type);	
		void setIsClick(bool isClick);	

		//bool isBuildable(Position pos); /* vérifie si la tour peut etre construite a la position 'pos' */
		Position target(vector<Alien> aliens); 
};

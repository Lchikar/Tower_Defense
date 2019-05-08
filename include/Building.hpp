#ifndef DEF_BUILDING
#define DEF_BUILDING
 
#include <iostream>
#include <string>

#include "Entity.hpp"
#include "Tower.hpp"

enum TypeBuild
{
	radar,
	weapon,
	stock,
};

class Building : public Entity{
	private :
		int value; /* valeur de l'upgrade */
		TypeBuild type; /* type d'upgrade */

	public:
		Building(int value, TypeBuild type);
		~Building();

		int getValue();
		TypeBuild getType();

		void setValue(int value);
		void setType(TypeBuild type);


		bool isBuildable(Position pos); /* vérifie si le batiment peut etre construit a la position 'pos' */
		void upgrade(Tower* tower); /* améliore la tour 'tower' */
};

#endif

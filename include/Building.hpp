#ifndef DEF_BUILDING
#define DEF_BUILDING
 
#include <iostream>
#include <string>

#include "Entity.h"
#include "Tower.h"

class Building : public Entity{
	private :
		int value; /* valeur de l'upgrade */
		string type; /* type d'upgrade */

	public:
		Building();
		~Building();

		int getValue();
		string getType();

		void setValue(int value);
		void setType(string type);


		bool isBuildable(Position pos); /* vérifie si le batiment peut etre construit a la position 'pos' */
		void upgrade(Tower* tower); /* améliore la tour 'tower' */
};

#endif

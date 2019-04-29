#ifndef DEF_PATH
#define DEF_PATH
 
#include <iostream>
#include <string>


//decrit le type de noeud du chemin
typedef enum {input = 0, output = 1, bend = 2, cross = 3} NodeType;

class Path{

	private:
		dict NodeType graph; //representation du chemin par un graphe
	public :
		Path();
		~Path();

		NodeType geGraph();

		//ajout setter grace au fichier ppm ?

}

#endif
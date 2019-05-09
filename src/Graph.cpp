#include <iostream>
#include <string>

#include "../include/Graph.hpp"

Graph(vector<Arc> const &arcs, int nb_nodes) {
	adjencyList.resize(nb_nodes);

	for(auto &arc : arcs){
		int src = arc.src;
		int dest = arc.dest;
		int weight = arc.weight;

		(this->adjencyList)[src].push_back(make_pair(dest, weight));
	}

	// création liste chemins
}

vector<vector<int>> getAdjencyList(){
	vector<vector<int>> list = this-> adjencyList;
	return res;
}

vector<Path> get_paths(){
	vector<Path> res = this->paths;
	return res;
}

List<int> get_successors(int node){
	List<int> successors;
	foreach((successor, weight) in adjencyList[node]){
		successors.push_back(successor.get(0));
	}
	return successors;
}

// récupérer tous les chemins:
 
// List<Noeud> listeCourante = new List<Noeud>;
// List<List<Noeud> > tousLesChemins = new List<List<Noeud> >;
// Noeud leNoeudDeDepart;
// leNoeudDeDepart.examiner(listeCourante, tousLesChemins);

// void Noeud::examiner(List<Noeud> liste, List<List<Noeud> > total)
// {
//     if( ! this.estDans( liste ))
//     {
//         List<Noeud> nouvelle = new List<Noeud>(liste); // recopie
//         nouvelle.add(this);
//         total.add(nouvelle);
//         foreach fils in lesNoeudsVoisins
//         {
//             fils.examiner(nouvelle, total);
//         }
//     }
// }
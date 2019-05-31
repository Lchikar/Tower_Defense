#pragma once
 
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream> 
#include <cctype>

using namespace std;

class Graph {
	
	private:
		// dictionnaire d'adjacence avec :
		// cles = sommets
		// valeurs = liste de couples (successeur, poid)
		map<int,vector<pair<int,int>>> adj;

	public:
		Graph();
		~Graph();

		map<int,vector<pair<int,int>>> getAdj();		

		void addVertex(int u);
		
		void addEdge(int u, int v, int w);

		vector<int> successors(int u);

		int weight(int u, int v);

		vector<pair<int,int>> edges();

		void update_weight(int u, int v, int w);

		int pop_closest_vertex(vector<int> *vertices, vector<int> distances);

		vector<int> distances(int src);

		map<int,vector<pair<int,int>>> Dijkstra(int src);

		bool exists_path(int src, int dest);

		vector<vector<int>> read_nodes(string path, int* nbNodes);

};
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream> 
#include <cctype>

#include "../include/Graph.hpp"



using namespace std;

Graph::Graph(){};
Graph::~Graph(){};

using namespace std;

map<int,vector<pair<int,int>>> Graph::getAdj(){
	return this->adj;
}

//vérifie le fchier itd et extrait les informations sur les noeuds
vector<vector<int>> Graph::read_nodes(string path, int* nbNodes){
	*nbNodes = -1;
	// le constructeur de ifstream permet d'ouvrir un fichier en lecture 
	ifstream file(path, ios::in); 

	if(!file){
		std::cout << "Opening itd file failed\n";
		return vector<vector<int>>();
	}

	// ce test échoue si le fichier n'est pas ouvert 
	if (file){
		vector<vector<int>> infoNodes;

		string line; // variable contenant chaque ligne lue 

		int cptLine = 0;
		int idInfo = 0;
		int readNodes = 0;
		string delimiter = " ";
		size_t pos = 0;
		string token;

		int idNode;
		vector<int> infos;
		
		while (getline(file,line)){ 
			cptLine++;
			//std::cout << "\ttest line " << cptLine << "\n";

			switch(cptLine){
				//@ITD
				case 1: if(!(0 == line.compare(0,4,"@ITD"))){
						fprintf(stderr, "Error line 1: '@ITD n' expected\n");
						file.close();
						return vector<vector<int>>();
					}
					//std::cout << line << " ok\n";
					break;
				
				//couleur carte
				case 2: 
					if(line[0] == '#') cptLine--;
					else if(!(0 == line.compare(0,5,"carte"))){
							fprintf(stderr, "Error line %d: 'carte path.ppm' expected\n", cptLine);
							file.close();
							return vector<vector<int>>();
						}
					//std::cout << line << " ok\n";
					break;
				//couleur chemin 
				case 3:
					if(line[0] == '#') cptLine--;
					else if(!(0 == line.compare(0,6,"chemin"))){
							fprintf(stderr, "Error line %d: 'chemin x x x' expected\n", cptLine);
							file.close();
							return vector<vector<int>>();
						}
					//std::cout << line << " ok\n";
					break;
				//couleur noeud
				case 4: 
					if(line[0] == '#') cptLine--;
					else if(!(0 == line.compare(0,5,"noeud"))){
							fprintf(stderr, "Error line %d: 'noeud x x x' expected\n", cptLine);
							file.close();
							return vector<vector<int>>();
						}
					//std::cout << line << " ok\n";
					break;
				//couleur construct
				case 5:
					if(line[0] == '#') cptLine--;
					else if(!(0 == line.compare(0,9,"construct"))){
							fprintf(stderr, "Error line %d: 'construct x x x' expected\n", cptLine);
							file.close();
							return vector<vector<int>>();
						}
					//std::cout << line << " ok\n";
					break;
				//couleur in
				case 6:
					if(line[0] == '#') cptLine--;
					else if(!(0 == line.compare(0,2,"in"))){
							fprintf(stderr, "Error line %d: 'in x x x' expected\n", cptLine);
							file.close();
							return vector<vector<int>>();
						}
					//std::cout << line << " ok\n";
					break;
				//couleur out
				case 7:
					if(line[0] == '#') cptLine--;
					else if(!(0 == line.compare(0,3,"out"))){
							fprintf(stderr, "Error line %d: 'out x x x' expected\n", cptLine);
							file.close();
							return vector<vector<int>>();
						}
					//std::cout << line << " ok\n";
					break;
				//nb noeuds
				case 8: if(line[0] == '#') cptLine--;
						else {
							for(int i = 0; i < line.length(); i++){
								if(!isdigit(line[i])){
									fprintf(stderr, "Error line %d: integer expected\n", cptLine);
									file.close();
									return vector<vector<int>>();
								}
							}
							//cout << "\tNB NODES : " << line << "\n";
							*nbNodes = stoi(line);
							infoNodes.resize(stoi(line));
						}
					//std::cout << line << " ok\n";
					break;
				//infos noeuds
				default:
				if(line[0] == '#') cptLine--;
				else{

					readNodes++;
					// cout << "INFO NODE : " << line << "\n";
					// file<<var -> stock un mot dans var avec ' ' en séparateur
					while ((pos = line.find(delimiter)) != string::npos) {
					    token = line.substr(0, pos);
					    if(0 == idInfo){
					    	idNode = stoi(token);
					    }
					    else{
					    	infos.push_back(stoi(token));
				  		//for (auto i = infos.begin(); i != infos.end(); ++i)
						// 	std::cout << *i << ' ';
						//cout << "\n";
					    }

					    line.erase(0, pos + delimiter.length());
					    idInfo++;
					}

					// for (auto i = infos.begin(); i != infos.end(); ++i)
					// 	std::cout << *i << ' ';
					// cout << "\n";
					// cout << "ajout dernier : '" << line << "'\n";
					if(0 != line.length()){
						infos.push_back(stoi(line));

					//cout << idNode<<"\n";
					//for (auto i = infos.begin(); i != infos.end(); ++i)
    				//	std::cout << *i << ' ';
    				//cout << "\n";
						
					}
				    infoNodes.insert(idNode+infoNodes.begin(), infos);
				    infos.clear();
				    idInfo = 0;
				}
				////std::cout << line << " ok\n";	
			}
		}
		if(*nbNodes != readNodes){
			fprintf(stderr, "Error: expected %d nodes, read %d\n", *nbNodes, readNodes);
			file.close();
			return vector<vector<int>>(); 
		}
		infoNodes.resize(*nbNodes);
		file.close();
		return infoNodes; 
	}
}

void Graph::addVertex(int u) { 
	if(this->adj.count(u) > 0){
		fprintf(stderr, "Node %d already existing\n", u);
	}
	else
		this->adj.insert(pair<int,vector<pair<int,int>>>(u, vector<pair<int,int>>()));
} 

void Graph::addEdge(int u, int v, int w){
	if(0 == this->adj.count(u)){
		fprintf(stderr, "Vertex %d not existing\n", u);
		return;
	}
	if(0 == this->adj.count(v)){
		fprintf(stderr, "Vertex %d not existing\n", v);
		return;
	}

	for(auto i = this->adj[u].begin(); i != this->adj[u].end(); i++){
		if((*i).first == v){
			fprintf(stderr, "Edge %d--%d already existing\n", u, v);
			return;
		}
	}
	for(auto i = this->adj[v].begin(); i != this->adj[v].end(); i++){
		if((*i).first == u){
			fprintf(stderr, "Edge %d--%d already existing\n", u, v);
			return;
		}
	}
	this->adj[u].push_back(pair<int,int>(v,w));
}  

vector<int> Graph::successors(int u){
	vector<int> succ;
	if(0 == this->adj.count(u)){
		fprintf(stderr, "Node %d not existing\n", u);
		return vector<int>();
	}
	
	for(auto i = this->adj[u].begin(); i != this->adj[u].end(); ++i)
		succ.push_back((*i).first);
	return succ;
}

int Graph::weight(int u, int v){
	if(this->adj.count(u) > 0 && this->adj.count(v) > 0){
		for(auto it = this->adj[u].begin(); it != this->adj[u].end(); it++){
			if((*it).first == v)
				return (*it).second;
		}
	}
	fprintf(stderr, "Invalid nodes\n");
	return -1;
}

void Graph::update_weight(int u, int v, int w){
	if(this->adj.count(u) > 0 && this->adj.count(v) > 0){
		for(auto it = this->adj[u].begin(); it != this->adj[u].end(); it++){
			if((*it).first == v)
				(*it).second = w;
		}
	}
	fprintf(stderr, "Invalid nodes\n");
}

int Graph::pop_closest_vertex(vector<int> *vertices, vector<int> distances){
	int u = -1;
	int dist_min = 99999;
	for(int candidat : *vertices){
		if(distances[candidat] < dist_min){
			dist_min = distances[candidat];
			u = candidat;
		}
	}
	if(-1 != u){
		vector<int>::iterator index = find((*vertices).begin(), (*vertices).end(), u);
		(*vertices).erase(index);
	}
	return u;
}

vector<int> Graph::distances(int src){
	vector<int> to_do;
	for(auto i = this->adj.begin(); i != this->adj.end(); ++i){
		to_do.push_back((*i).first);
	}
	vector<int> dist;
	for(auto i = this->adj.begin(); i != this->adj.end(); ++i){
		dist.push_back(999999);
	}
	dist[src] = 0;

	while(!to_do.empty()){
		int u = pop_closest_vertex(&to_do, dist);
		if(-1 == u)
			return dist;
		for(int v : successors(u)){
			dist[v] = std::min(dist[v], dist[u]+weight(u,v));
		}
	}
	return dist;
}

map<int,vector<pair<int,int>>> Graph::Dijkstra(int src){
	vector<int> to_do;
	for(auto i = this->adj.begin(); i != this->adj.end(); ++i){
		to_do.push_back((*i).first);
	}
	vector<int> dist;
	for(auto i = this->adj.begin(); i != this->adj.end(); ++i){
		dist.push_back(999999);
	}
	dist[src] = 0;

	map<int,vector<pair<int,int>>> path;

	while(!to_do.empty()){
		int u = pop_closest_vertex(&to_do, dist);
		if(-1 == u)
			return path;
		for(int v : successors(u)){
			int est_dist = dist[u] + weight( u, v);
			if(est_dist < dist[v]){
				dist[v] = est_dist;
				vector<pair<int,int>> arete;
				arete.push_back(pair<int,int>(u,v));
				path[v] = path[u];
				path[v].push_back(pair<int,int>(u,v));
			}
		}
	}
	return path;
}

bool Graph::exists_path(int src, int dest){
	if(src == dest)
		return true;
	vector<int> succ = this->successors(src);

	printf("ok ?\n");
	for(int v : succ){
		printf("succ[%d] = %d\n", src, v);
		if(v == dest)
			return true;
		if(v != src)
			return (false || exists_path(v, dest));	
	}
	return false;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "../include/Graph.hpp"



using namespace std;

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

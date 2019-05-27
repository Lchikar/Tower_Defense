#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void addVertex(map<int,vector<pair<int,int>>> *adj, int u) { 
	if((*adj).count(u) > 0){
		fprintf(stderr, "Node %d already existing\n", u);
	}
	else
		(*adj).insert(pair<int,vector<pair<int,int>>>(u, vector<pair<int,int>>()));
} 

void addEdge(map<int,vector<pair<int,int>>> *adj, int u, int v, int w){
	if(0 == (*adj).count(u)){
		fprintf(stderr, "Vertex %d not existing\n", u);
		return;
	}
	if(0 == (*adj).count(v)){
		fprintf(stderr, "Vertex %d not existing\n", v);
		return;
	}

	for(auto i = (*adj)[u].begin(); i != (*adj)[u].end(); i++){
		if((*i).first == v){
			fprintf(stderr, "Edge %d--%d already existing\n", u, v);
			return;
		}
	}
	(*adj)[u].push_back(pair<int,int>(v,w));
}  

vector<int> successors(map<int,vector<pair<int,int>>> *adj, int u){
	vector<int> succ;
	if(0 == (*adj).count(u)){
		fprintf(stderr, "Node %d not existing\n", u);
		return vector<int>();
	}
	
	for(auto i = (*adj)[u].begin(); i != (*adj)[u].end(); ++i)
		succ.push_back((*i).first);
	return succ;
}

int weight(map<int,vector<pair<int,int>>> adj, int u, int v){
	if(adj.count(u) > 0 && adj.count(v) > 0){
		for(auto it = adj[u].begin(); it != adj[u].end(); it++){
			if((*it).first == v)
				return (*it).second;
		}
	}
	fprintf(stderr, "Invalid nodes\n");
	return -1;
}

int pop_closest_vertex(vector<int> *vertices, vector<int> distances){
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

vector<int> distances(map<int,vector<pair<int,int>>> *adj, int src){
	vector<int> to_do;
	for(auto i = (*adj).begin(); i != (*adj).end(); ++i){
		to_do.push_back((*i).first);
	}
	vector<int> dist;
	for(auto i = (*adj).begin(); i != (*adj).end(); ++i){
		dist.push_back(999999);
	}
	dist[src] = 0;

	while(!to_do.empty()){
		int u = pop_closest_vertex(&to_do, dist);
		if(-1 == u)
			return dist;
		for(int v : successors(adj,u)){
			dist[v] = std::min(dist[v], dist[u]+weight(*adj,u,v));
		}
	}
	return dist;
}

map<int,vector<pair<int,int>>> Dijkstra(map<int,vector<pair<int,int>>> *adj, int src){
	vector<int> to_do;
	for(auto i = (*adj).begin(); i != (*adj).end(); ++i){
		to_do.push_back((*i).first);
	}
	vector<int> dist;
	for(auto i = (*adj).begin(); i != (*adj).end(); ++i){
		dist.push_back(999999);
	}
	dist[src] = 0;

	map<int,vector<pair<int,int>>> path;

	while(!to_do.empty()){
		int u = pop_closest_vertex(&to_do, dist);
		if(-1 == u)
			return path;
		for(int v : successors(adj,u)){
			int est_dist = dist[u] + weight(*adj, u, v);
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

int main(int argc, char const *argv[])
{
	map<int,vector<pair<int,int>>> adjency;
//creer map adj
	addVertex(&adjency, 0); 
    addVertex(&adjency, 1); 
    addVertex(&adjency, 2); 
    addVertex(&adjency, 3); 
    addVertex(&adjency, 4); 
    addVertex(&adjency, 4); 
    addVertex(&adjency, 5); 
    addVertex(&adjency, 6);
    addVertex(&adjency, 7);
    addVertex(&adjency, 8);
    addVertex(&adjency, 9);
    addVertex(&adjency, 10);
    addVertex(&adjency, 11);


    addEdge(&adjency, 0, 1, 40);
    addEdge(&adjency, 1, 0, 40);
    addEdge(&adjency, 1, 2, 40);

    addEdge(&adjency, 1, 20, 40);

    addEdge(&adjency, 2, 1, 40);
    addEdge(&adjency, 2, 3, 40);
    addEdge(&adjency, 3, 2, 40);
    addEdge(&adjency, 3, 4, 40);
    addEdge(&adjency, 4, 3, 40);
    addEdge(&adjency, 4, 5, 40);
    addEdge(&adjency, 4, 8, 40);
    addEdge(&adjency, 5, 4, 40);
    addEdge(&adjency, 5, 6, 40);
    addEdge(&adjency, 6, 5, 40);
    addEdge(&adjency, 6, 7, 40);
    addEdge(&adjency, 7, 6, 40);
    addEdge(&adjency, 7, 10, 40);
    addEdge(&adjency, 8, 4, 40);
    addEdge(&adjency, 8, 9, 40);
    addEdge(&adjency, 9, 8, 40);
    addEdge(&adjency, 9, 10, 40);
    addEdge(&adjency, 10, 7, 40);
    addEdge(&adjency, 10, 9, 40);
    addEdge(&adjency, 10, 11, 40);
    addEdge(&adjency, 11, 10, 40);

	for (int i = 0; i < adjency.size(); i++){
		cout << "node " << i << ": ";
	    for (int j = 0; j < adjency[i].size(); j++){
	        cout << "(" << adjency[i][j].first << ", " << adjency[i][j].second << ") ";
	    }
	    cout << "\n";
	}
	cout << "\n";
	
	// for(int u = 0; u < adjency.size(); u++){
	// 	vector<int> succ_u = successors(&adjency, u);
	// 	for (int v = 0; v < succ_u.size(); v++){
	// 		printf("\tweight(%d, %d) = %d\n", u, succ_u[v], weight(adjency, u, succ_u[v]));
	// 	}
	// vector<int> succ_u = successors(&adjency, u);
	// 	if(!succ_u.empty()){
	// 		cout << "successors of " << u << ": ";
	// 		for(int i = 0; i < succ_u.size(); i++)
	// 			cout << "(" << succ_u[i] << ", " << weight(adjency,u,i) << ") ";
	// 		cout << "\n";
	// 	 }
	// }

//tests Dijkstra

	vector<int> sommets;
	sommets.push_back(0);	
	sommets.push_back(1);	
	sommets.push_back(2);	
	sommets.push_back(3);

	vector<int> dist;
	dist.push_back(5);
	dist.push_back(1);
	dist.push_back(2);
	dist.push_back(3);

	printf("Somment plus proche de 0 : %d\n", pop_closest_vertex(&sommets, dist));

	vector<int> dist_u = distances(&adjency, 0);
	printf("\tDistances de 0:\n");
	for(int i = 0; i < dist_u.size(); i++){
		printf("(%d, %d) ", i, dist_u[i]);
	}
	printf("\n");

	map<int,vector<pair<int,int>>> pcc = Dijkstra(&adjency, 0);
	printf("PCC depuis 0\n");
	for (int i = 0; i < pcc.size(); i++){
		cout << "vers " << i << ": ";
	    for (int j = 0; j < pcc[i].size(); j++){
	        cout << "(" << pcc[i][j].first << ", " << pcc[i][j].second << ") ";
	    }
	    cout << "\n";
	}
	cout << "\n";	

	return 0;
}
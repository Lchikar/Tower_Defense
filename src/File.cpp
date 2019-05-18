#include <fstream> 
#include <string>  
#include <iostream> 
#include <vector>
#include <cctype>


using namespace std;

//vérifie le fchier itd et extrait les informations sur les noeuds
vector<vector<int>> read_nodes(string path, int* nbNodes){
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


// int main(int argc, char const *argv[])
// {
// 	int i, j;
// 	int nbNodes;
// 	vector<vector<int>> infoNodes = read_nodes("testmap.itd", &nbNodes);
// 	if(infoNodes.empty()){
// 		std::cout << "infoNodes vide\n";
// 	}

// 	for (int i = 0; i < infoNodes.size(); i++){
// 		cout << "node " << i << ": ";
// 	    for (int j = 0; j < infoNodes[i].size(); j++){
// 	        cout << infoNodes[i][j] << " ";
// 	    }
// 	    cout << "\n";
// 	}

// 	return 0;
// }

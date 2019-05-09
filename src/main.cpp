#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "../include/Entity.hpp"
#include "../include/Map.hpp"
#include "../include/Building.hpp"
#include "../include/Tower.hpp"
#include "../include/Alien.hpp"
#include "../include/Path.hpp"
#include "../include/Position.hpp"

/* Dimensions de la fenetre 
static unsigned int WINDOW_WIDTH = 1010;
static unsigned int WINDOW_HEIGHT = 750;
*/

void print_error(){
	fprintf(stderr, "Mauvais usage\n './itd map.itd' est demandé\n");
}


static int main(int argc, char** argv){

	/* Ouvrir et tester map */
	/* On est censés avoir ./itd map.itd */

	if(argc != 2){
		print_error();
		EXIT_ERROR;
	}

	if(0 != strcmp('.itd', argv[1]+strlen(argv[1])-4)){
		print_error();
		EXIT_ERROR;
	}

	if(!is_valid_itd(argv[1])){
		fprintf(stderr, "Map not valid\n");
		EXIT_ERROR;	
	}

	/* Créer chemins à partir de la carte */
	Path* paths = path_list(argv[1]);
	if(!paths){
		fprintf(stderr, "No path generated\n");
		EXIT_ERROR;
	}

	/* INITIALISATION ENTITES */
	/* Fonctions init ? */

	Tower* towers = (Towers*)alloc(NB_TOWER_MAX*sizeof(Tower));
	if(!towers){
		fprintf(stderr, "Alloc error towers\n");
		EXIT_ERROR;
	}
	else{
		nb_towers = 0;
	}

	Building* buildings = (Building*)alloc(NB_BUIDING_MAX*sizeof(Building));
	if(!buildings){
		fprintf(stderr, "Alloc error buildings\n");
		EXIT_ERROR;
	}
	else{
		nb_buildings = 0;
	}

	Alien* aliens = (Aliens*)alloc(NB_alien_MAX*sizeof(Alien));
	if(!aliens){
		fprintf(stderr, "Alloc error aliens\n");
		EXIT_ERROR;
	}
	else{
		nb_aliens = 0;
	}

	/* INIT GAMEPLAY */
	init_life();
	init_money();
	init_time();
	init_waves();

	/* Boucle jeu */
	while(time % 1/10 sec){ /* toutes les k/10e de secondes */
		/* game over */
		if(num_wave == 50){
			win();
			return 0;
		}
		if(vie <= 0){
			lose()
			return 0;
		}

		/* si nouvelle vague load aliens (nb aliens selon n° vague) */
		if(nouvelle_vague){
			while(i < nb_aliens_a_ajouter){
				aliens.push(type alien);
				i++;	
			}/* ajout des aliens à la liste */	
		}
		
		/* test si clic achat */
		/* fonction shop_management ? */
		if(clic in zone_achat){/* test sur les coordo */
			foreach(produit in article){
				if(clic in zone_produit){
					if(money >= article.prix){
						money -= article.prix;
						/* placer article */
						if(produit.is_placeable){
							ajout_produit in list; /* ajout à towers ou buildings */
							affichage.update_towers(); /* ou update_building */	
						}
					}
				}
			}
		}

		/* déplacer aliens */
		for(alien in aliens){
			alien.move(); /* fait avancer selon un chemin */ 
		}
		affichage.update_aliens();

		/* faire tirer les tours */
		for(tower in towers){
			target = tower.fire(); /* tire et renvoie l'alien touché ou 0 */
			if(target.is_dead()){
				money += target.get_reward();
				aliens.pop(alien);
				if(aliens.is_empty){ /* si tous les aliens on été tués */
					vague++;
				}
				affichage.update();
			}
		}
	}

	return 0;
}

#include "heuristicAi.hpp"
#include "elementList.hpp"
#include "mobileElement.hpp"
#include <iostream>

/**
 * HeuristicAI Class
**/

using namespace ai;

HeuristicAI::HeuristicAI(state::LevelState& mainLevelState) : DumbAI(mainLevelState){
}
bool HeuristicAI::moveToClosest(engine::Engine& engine,const PathMap& path, state::Element* element){
	
	int x_elem = element->getX();
	int y_elem = element->getY();
	int nbStep = ((state::MobileElement*)element)->getNbStep();
	
	int x_move = 0;
	int y_move = 0;
	
	int width = path.getWidth();
	int* weights = path.getWeights();
	
	int value = 999;
	
	for(int i=0; i<2*nbStep+1; i++){
		for(int j=0; j<2*nbStep+1; j++){
			
			int x_tmp = x_elem - nbStep + i;
			int y_tmp = y_elem - nbStep + j;
			
			if(path.isValid(x_tmp, y_tmp) && weights[x_tmp * width + y_tmp]<999){		//on s'assure que la case est dans las grille et n'est pas un obstacle ou un personnage
				
				if(weights[x_tmp * width + y_tmp] <  value && weights[x_tmp * width + y_tmp] !=0){		//on cherche la case avec le poids le moins fort dans la limite du nombre de pas
					value = weights[x_tmp * width + y_tmp];
					x_move = x_tmp;
					y_move = y_tmp;
				}
			}
		}
	}
	if(value<999){		//si un déplacement est réalisable, on créée une commande de déplacement
		std::cout << "x_elem " << x_elem << std::endl;
		std::cout << "y_elem " << y_elem << std::endl;
		std::cout << "x " << x_move << std::endl;
		std::cout << "y " << y_move << std::endl;
		engine::MoveCommand* move = new engine::MoveCommand(x_move, y_move, element);
		engine.addCommand(move);
		return true;
	}
	return false;
}
void HeuristicAI::run(engine::Engine& engine){

	PathMap playerCharsMap(mainLevelState);
	state::ElementList characters = mainLevelState.getElementList();
	
	playerCharsMap.clear();																//on réinitialise les éléments de la carte de distance
	
	for(int i=0; i<characters.size(); i++){												//on détermine le prochain mouvement des monstres
		
		state::Element* curr_element = characters.getElement(i);
		
		if( ! ((state::MobileElement*)curr_element)->isPlayerCharacter()){				//on récupère un monstre 
			if (((state::MobileElement*)curr_element)->getTurnPlayed() == false){		//on s'assure qu'il peut jouer
				
				for(int j=0; j<characters.size(); j++){												//on calcul la carte de distance des personnages du joueurs
		
					if(((state::MobileElement*)characters.getElement(j))->isPlayerCharacter()){		//on récupère un personnage du joueur 
			
						playerCharsMap.addElement(characters.getElement(j));						//on l'ajoute sur la carte des distances
					}
				}
				playerCharsMap.dijsktra();
				
				moveToClosest(engine, playerCharsMap, curr_element);
				
				playerCharsMap.display();
			}
		}
	}
}


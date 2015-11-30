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
	
	std::cout << "moveToClosest\n";
	int width = path.getWidth();
	
	int x_elem = element->getX();
	int y_elem = element->getY();
	
	int x_move = 0;
	int y_move = 0;
	
	int* weights = path.getWeights();
	
	int value = 999;
	
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			
			int x_tmp = x_elem+i;
			int y_tmp = y_elem+j;
			
			if(path.isValid(x_tmp, y_tmp) && weights[x_tmp * width + y_tmp]<999){		//on s'assure que la case est dans las grille et n'est pas un obstacle ou un personnage
				
				if(weights[x_tmp * width + y_tmp] <  value){
					value = weights[x_tmp * width + y_tmp];
					x_move = x_tmp;
					y_move = y_tmp;
				}
			}
		}
	}
	if(value<999){		//si un déplacement est réalisable, on met à jour les coordonnées de l'élément
		
		std::cout << "value inf 999\n";
		element->setX(x_move);
		element->setY(y_move);
		return true;
	}
	return false;
}
void HeuristicAI::run(engine::Engine& engine){

	PathMap playerCharsMap(mainLevelState);
	state::ElementList characters = mainLevelState.getElementList();
	
	playerCharsMap.clear();																//on réinitialise les éléments de la carte de distance
	
	for(int i=0; i<characters.size(); i++){												//on calcul la carte de distance des personnages du joueurs
		
		if(((state::MobileElement*)characters.getElement(i))->isPlayerCharacter()){		//on récupère un personnage du joueur 
			
			std::cout << "addElement\n";
			playerCharsMap.addElement(characters.getElement(i));						//on l'ajoute sur la carte des distances
		}
	}
	playerCharsMap.dijsktra();
	playerCharsMap.display();
	
	for(int i=0; i<characters.size(); i++){												//on détermine le prochain mouvement des monstres
		
		state::Element* curr_element = characters.getElement(i);
		
		if( ! ((state::MobileElement*)curr_element)->isPlayerCharacter()){				//on récupère un monstre 
			if (((state::MobileElement*)curr_element)->getTurnPlayed() == false){		//on s'assure qu'il peut jouer
				
				if(moveToClosest(engine, playerCharsMap, curr_element)){
				
					int x = curr_element->getX();
					int y = curr_element->getY();
					std::cout << "x " << x << std::endl;
					std::cout << "y " << y << std::endl;
				
					engine::MoveCommand* move = new engine::MoveCommand(x, y, curr_element);
					engine.addCommand(move);
				}
			}
		}
	}
}


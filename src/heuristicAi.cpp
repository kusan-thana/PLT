#include "heuristicAi.hpp"
#include "elementList.hpp"
#include "mobileElement.hpp"

/**
 * HeuristicAI Class
**/

using namespace ai;

HeuristicAI::HeuristicAI(state::LevelState& mainLevelState) : DumbAI(mainLevelState), playerCharsMap(mainLevelState), monstersMap(mainLevelState){
	
	state::ElementList characters = mainLevelState.getElementList();
	
	for(int i=0; i<characters.size(); i++){
		
		if( ! ((state::MobileElement*)characters.getElement(i))->isPlayerCharacter()){		//on récupère un personnage du joueur 
			playerCharsMap.clear();
			playerCharsMap.addElement(characters.getElement(i));						//on l'ajoute sur la carte des distances
		}
	}
}
bool HeuristicAI::moveToClosest(engine::Engine& engine,const PathMap& path, state::Element* element){
	
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
		
		element->setX(x_move);
		element->setY(y_move);
		return true;
	}
	return false;
}
void HeuristicAI::run(engine::Engine& engine, state::Element* element){

	state::ElementList characters = mainLevelState.getElementList();
	
	if (((state::MobileElement*)element)->getTurnPlayed() == false){		//on s'assure qu'il peut jouer
		
		if(moveToClosest(engine, playerCharsMap, element)){
		
			int x = element->getX();
			int y = element->getY();
		
			engine::MoveCommand* move = new engine::MoveCommand(x, y, element);
			engine.addCommand(move);
		}
	}
}


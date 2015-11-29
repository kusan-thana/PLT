#include "heuristicAi.hpp"
#include "elementList.hpp"
#include "monster.hpp"

/**
 * HeuristicAI Class
**/

using namespace ai;

HeuristicAI::HeuristicAI(state::LevelState& mainLevelState) : DumbAI(mainLevelState), playerCharsMap(mainLevelState), monstersMap(mainLevelState){
}
bool HeuristicAI::moveToClosest(engine::CommandSet& commands,const PathMap& path){
	
	state::ElementList characters = mainLevelState.getElementList();
	
	for(int i=0; i<characters.size(); i++){
		
		if(((state::Monster*)characters.getElement(i))->isPlayerCharacter()){
			
			//~ path.clear();
			//~ path.addElement(characters.getElement(i));
		}
		//~ path.dijsktra();
	}
}
void HeuristicAI::run(engine::CommandSet& commands){

	state::ElementList characters = mainLevelState.getElementList();
	
	for(int i=0; i<characters.size(); i++){
		
		if( ! ((state::Monster*)characters.getElement(i))->isPlayerCharacter()){					//on récupère un monstre
			if (((state::MobileElement*)(characters.getElement(i)))->getTurnPlayed() == false){		//on s'assure qu'il peut jouer
				
				int x = characters.getElement(i)->getX();
				int y = characters.getElement(i)->getY();
				
				moveToClosest(commands, playerCharsMap);
				
				//~ engine::MoveCommand* move = new engine::MoveCommand(x, y, characters.getElement(i));
				//~ engine.addCommand(move);
			}
		}
	}
	
	
	
	//~ state::ElementList elementList = mainLevelState.getElementList();
	//~ int x_hero = elementList.getElement(0)->getX();
	//~ int y_hero = elementList.getElement(0)->getY();
	//~ 
	//~ for (int i = rand() % (elementList.size() - 3) + 3; i < elementList.size(); i++){ //Selection aléatoire du personnage ennemi pour éviter que le 1er soit bloqué par les autres
		//~ if (((state::MobileElement*)(elementList.getElement(i)))->getTurnPlayed() == false){
			//~ int x = elementList.getElement(i)->getX();
			//~ int y = elementList.getElement(i)->getY();
			//~ 
			//~ if (abs (x- x_hero) <= 1 && abs(y - y_hero) <= 1){ //Le personnage attaque le héros si il est suffisamment proche
				//~ engine::AttackCommand* attack = new engine::AttackCommand(mainLevelState.getElementList().getElement(i), mainLevelState.getElementList().getElement(0));
				//~ engine.addCommand(attack);
			//~ }
			//~ if (x > x_hero)
				//~ x--;
			//~ else if (x < x_hero)
				//~ x++;
			//~ 
			//~ if (y > y_hero)
				//~ y--;
			//~ else if (y < y_hero)
				//~ y++;
			//~ 
			//~ if(mainLevelState.getElementList().getElement(x,y)){
				//~ x = elementList.getElement(i)->getX()+ rand()%3-1;
				//~ y = elementList.getElement(i)->getY()+ rand()%3-1;
			//~ }
			//~ engine::MoveCommand* move = new engine::MoveCommand(x, y, mainLevelState.getElementList().getElement(i));
			//~ engine.addCommand(move);	
		//~ }	
	//~ }
}

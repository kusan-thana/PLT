#include "dumbAi.hpp"
#include "elementList.hpp"
#include "mobileElement.hpp"
#include "attackCommand.hpp"
#include <iostream>
#include <time.h>
/**
 * DumbAI Class

 *Les ennemies se dirigent vers le h�ros et l'attaque. Si ils sont bloqu�s dans leur mouvements, ils vont autre part al�atoirement
**/

using namespace ai;

DumbAI::DumbAI(const state::LevelState& mainLevelState) : AI(mainLevelState){
	srand(time(NULL));
}
void DumbAI::dumbMove(int idx, engine::CommandSet& commands){
}
void DumbAI::run(engine::Engine& engine){
	//std::cout << mainLevelState.getElementList().getElement(0) << std::endl;
	
	state::ElementList elementList = mainLevelState.getElementList();
	int x_hero = elementList.getElement(0)->getX();
	int y_hero = elementList.getElement(0)->getY();
	
	for (int i = rand() % (elementList.size() ); i < elementList.size(); i++){ //Selection al�atoire du personnage ennemi pour �viter que le 1er soit bloqu� par les autres
		
		if( ! ((state::MobileElement*)elementList.getElement(i))->isPlayerCharacter()){
			if (((state::MobileElement*)(elementList.getElement(i)))->getTurnPlayed() == false){
				int x = elementList.getElement(i)->getX();
				int y = elementList.getElement(i)->getY();
				
				if (abs (x- x_hero) <= 1 && abs(y - y_hero) <= 1){ //Le personnage attaque le h�ros si il est suffisamment proche
					engine::AttackCommand* attack = new engine::AttackCommand(mainLevelState.getElementList().getElement(i), mainLevelState.getElementList().getElement(0));
					engine.addCommand(attack);
				}
				if (!((state::MobileElement*)elementList.getElement(i))->getMovePlayed()) {
					if (x > x_hero)
						x--;
					else if (x < x_hero)
						x++;

					if (y > y_hero)
						y--;
					else if (y < y_hero)
						y++;

					if (mainLevelState.getElementList().getElement(x, y)) {
						x = elementList.getElement(i)->getX() + rand() % 3 - 1;
						y = elementList.getElement(i)->getY() + rand() % 3 - 1;
					}
					engine::MoveCommand* move = new engine::MoveCommand(x, y, mainLevelState.getElementList().getElement(i));
					engine.addCommand(move);
				}
				else {
					engine::MoveCommand* move = new engine::MoveCommand(elementList.getElement(i)->getX(), elementList.getElement(i)->getY(), mainLevelState.getElementList().getElement(i));
					engine.addCommand(move);
				}
			}	
		}
	}

}

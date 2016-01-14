#include "ai.hpp"
#include <iostream>
#include <time.h>

/**
 * DumbAI Class
 * If character find an ennemy charac one step from him, it attacks it
 *Les personnages se dirigent vers le héros.
 *Si ils sont bloqués dans leur mouvements, ils vont autre part aléatoirement
**/

using namespace ai;

DumbAI::DumbAI(const state::LevelState& mainLevelState) : AI(mainLevelState){
	srand(time(NULL));
}
void DumbAI::dumbMove(int idx, engine::CommandSet& commands){
}
void DumbAI::run(engine::Engine& engine, server::Server& serv){
	//std::cout << mainLevelState.getElementList().getElement(0) << std::endl;
	
	state::ElementList elementList = mainLevelState.getElementList();
	int x_hero = elementList.getElement(0)->getX();
	int y_hero = elementList.getElement(0)->getY();
	
	for (int i = rand() % (elementList.size() ); i < elementList.size(); i++){ //Selection aléatoire du personnage ennemi pour éviter que le 1er soit bloqué par les autres
		
			if (((state::MobileElement*)(elementList.getElement(i)))->getTurnPlayed() == false){
				int x = elementList.getElement(i)->getX();
				int y = elementList.getElement(i)->getY();
				
				for (int k = 0; k < 9; k++) { //Dumb Attack only one case
					state::MobileElement* element = (state::MobileElement*) mainLevelState.getElementList().getElement(x + (k / 3) - 1, y + (k % 3) - 1);
					if (element){
						if (!element->isPlayerCharacter() && mainLevelState.getTurnToPlay() == state::PLAYER) {
							engine::AttackCommand* attack = new engine::AttackCommand(elementList.getElement(i), mainLevelState.getElementList().getElement(x + (k / 3) - 1, y + (k % 3) - 1));
							engine.addCommand(attack);

						}
						else if (element->isPlayerCharacter() && mainLevelState.getTurnToPlay() == state::OPPONENT) {
							engine::AttackCommand* attack = new engine::AttackCommand(elementList.getElement(i), mainLevelState.getElementList().getElement(x + (k / 3) - 1, y + (k % 3) - 1));
							engine.addCommand(attack);
						}
					}
				}
				if (!((state::MobileElement*)elementList.getElement(i))->getMovePlayed()) { //DumbMove Only one case
					if (x > x_hero)
						x--;
					else if (x < x_hero)
						x++;

					if (y > y_hero)
						y--;
					else if (y < y_hero)
						y++;

					if (mainLevelState.getElementList().getElement(x, y) || mainLevelState.getElementGrid().getCell(x,y)->getTypeID() != state::SPACE) {
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

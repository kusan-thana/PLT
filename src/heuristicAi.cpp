#include "heuristicAi.hpp"
#include "elementList.hpp"
#include "mobileElement.hpp"
#include "attackCommand.hpp"
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
	
	if (((state::MobileElement*)element)->getMovePlayed()) {	//si le personnage a déjà effectué son mouvement..
	
		engine::MoveCommand* move = new engine::MoveCommand(x_elem, y_elem, element);	//..on valide son tour
		engine.addCommand(move);
		return true;
	}
	
	for(int i=0; i<2*1+1; i++){		//Chercher si un ennemi est à porté
		for(int j=0; j<2*1+1; j++){		//la valeur "1" devra être remplacé par la portée de l'attaque!!
			
			int x_move = x_elem - 1 + i;	//la valeur "1" devra être remplacé par la portée de l'attaque!!
			int y_move = y_elem - 1 + j;
			
			if(weights[x_move * width + y_move] == 0){	//si un ennemi est a porté, on ne se déplace pas

				engine::MoveCommand* move = new engine::MoveCommand(x_elem, y_elem, element);
				engine.addCommand(move);
				return true;
			}
		}
	}
	
	for(int i=0; i<2*nbStep+1; i++){		//on cherche la case avec le poids le moins fort dans la limite du nombre de pas
		for(int j=0; j<2*nbStep+1; j++){
			
			int x_tmp = x_elem - nbStep + i;
			int y_tmp = y_elem - nbStep + j;
			
			if(path.isValid(x_tmp, y_tmp) && weights[x_tmp * width + y_tmp]<999){		//on s'assure que la case est dans las grille et n'est pas un obstacle ou un personnage
				
				if(weights[x_tmp * width + y_tmp] <  value && weights[x_tmp * width + y_tmp] !=0){		
					value = weights[x_tmp * width + y_tmp];
					x_move = x_tmp;
					y_move = y_tmp;
				}
			}
		}
	}
	if(value<999){		//si un déplacement est réalisable, on créée une commande de déplacement
		engine::MoveCommand* move = new engine::MoveCommand(x_move, y_move, element);
		engine.addCommand(move);
		return true;
	}
	return false;
}
bool HeuristicAI::attackToClosest(engine::Engine& engine,const PathMap& path, state::Element* element){
	
	int x_elem = element->getX();
	int y_elem = element->getY();
	
	int width = path.getWidth();
	int* weights = path.getWeights();
	
	for(int i=0; i<2*1+1; i++){		//Chercher si un ennemi est à porté
		for(int j=0; j<2*1+1; j++){
			
			int x_attack = x_elem - 1 + i;	//la valeur "1" devra être remplacé par la portée de l'attaque!!
			int y_attack = y_elem - 1 + j;
			
			if(weights[x_attack * width + y_attack] == 0){	//si un ennemi est a porté, on attaque

				engine::AttackCommand* attack = new engine::AttackCommand(element, mainLevelState.getElementList().getElement(x_attack, y_attack));
				engine.addCommand(attack);
				return true;
			}			
		}
	}
	return false;
	
}
void HeuristicAI::run(engine::Engine& engine){

	PathMap playerCharsMap(mainLevelState);
	state::ElementList characters = mainLevelState.getElementList();
	
	for(int i=0; i<characters.size(); i++){												//on détermine le prochain mouvement des monstres
		
		state::Element* curr_element = characters.getElement(i);
		
		//~ if( ! ((state::MobileElement*)curr_element)->isPlayerCharacter()){				//on récupère un monstre 
		if(mainLevelState.getTurnToPlay() == state::PLAYER   &&  ((state::MobileElement*)curr_element)->isPlayerCharacter() ||
		   mainLevelState.getTurnToPlay() == state::OPPONENT && !((state::MobileElement*)curr_element)->isPlayerCharacter()){
			
			if (((state::MobileElement*)curr_element)->getTurnPlayed() == false){		//on s'assure qu'il peut jouer
				
				playerCharsMap.clear();																//on réinitialise les éléments de la carte de distance
				for(int j=0; j<characters.size(); j++){												//on calcul la carte de distance des personnages du joueurs
		
					if(mainLevelState.getTurnToPlay() == state::OPPONENT){
						if(((state::MobileElement*)characters.getElement(j))->isPlayerCharacter()){		//on récupère un personnage du joueur 
				
							playerCharsMap.addElement(characters.getElement(j));						//on l'ajoute sur la carte des distances
						}
					}
					else if(mainLevelState.getTurnToPlay() == state::PLAYER){
						if( ! ((state::MobileElement*)characters.getElement(j))->isPlayerCharacter()){		//on récupère un personnage du joueur 
				
							playerCharsMap.addElement(characters.getElement(j));						//on l'ajoute sur la carte des distances
						}
					}
				}
				playerCharsMap.dijsktra();
					
				attackToClosest(engine, playerCharsMap, curr_element);
				
				playerCharsMap.clear();																//on réinitialise les éléments de la carte de distance
				for(int j=0; j<characters.size(); j++){												//on calcul la carte de distance des personnages du joueurs
		
					if(mainLevelState.getTurnToPlay() == state::OPPONENT){
						if(((state::MobileElement*)characters.getElement(j))->isPlayerCharacter()){		//on récupère un personnage du joueur 
				
							playerCharsMap.addElement(characters.getElement(j));						//on l'ajoute sur la carte des distances
						}
					}
					else if(mainLevelState.getTurnToPlay() == state::PLAYER){
						if( ! ((state::MobileElement*)characters.getElement(j))->isPlayerCharacter()){		//on récupère un personnage du joueur 
				
							playerCharsMap.addElement(characters.getElement(j));						//on l'ajoute sur la carte des distances
						}
					}
				}
				playerCharsMap.dijsktra();
				
				moveToClosest(engine, playerCharsMap, curr_element);
				playerCharsMap.display();
				break;
			}
		}
	}
}


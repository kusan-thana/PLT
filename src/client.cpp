#include "client.hpp"

#include "tileSet1.hpp"
#include "tileSet2.hpp"
#include "guiRender.hpp"

#include <iostream>
#include "engine.hpp" //A supprimer après parallélisme (?)
#include <iostream>
#include "levelState.hpp"
/**
 * Client Class
**/

using namespace client;

Client::Client() : engine(levelState), gui(levelState, engine),dumbAI(levelState), heuristicAi(levelState){
	
	this->tileSets.push_back(new render::TileSet1()); 	//GRID_LAYER			
	this->tileSets.push_back(new guiRender::TileSet3());	//MOVE_RANGE_LAYER       
	this->tileSets.push_back(new guiRender::TileSet3());	//CURSORS_LAYER       
	this->tileSets.push_back(new guiRender::TileSet3());	//TILE_LIST_LAYER       
	this->tileSets.push_back(new render::TileSet2());	//CHARACTERS_LAYER

}
void Client::setTileSet(render::SceneLayer sceneLayer, const render::TileSet* tileSet){
	
	this->tileSets[sceneLayer] = tileSet;
}
void Client::init(){

}
void Client::run(){
	

	this->init();

	while(acquireControls()){

		if (levelState.getTurnToPlay() == state::OPPONENT) {
			//dumbAI.run(engine);
			heuristicAi.run(engine);
		}
		else if(levelState.getTurnToPlay() == state::PLAYER) {
			if(gui.getStartPlayerAI()){
				heuristicAi.run(engine);
				//dumbAI.run(engine);
			}
			
		}
		engine.update();
		updateDisplay();
	}	
}

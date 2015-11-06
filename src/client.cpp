#include "client.hpp"

#include "tileSet1.hpp"
#include "tileSet2.hpp"
/**
 * Client Class
**/

using namespace client;

Client::Client() {
	
	this->tileSets.push_back(new render::TileSet1()); 	//GRID_LAYER
	this->tileSets.push_back(new render::TileSet2());	//CHARACTERS_LAYER
														//STATE_LAYER
}
void Client::setTileSet(render::SceneLayer sceneLayer, const render::TileSet* tileSet){
	
	this->tileSets[sceneLayer] = tileSet;
}
void Client::init(){
}
void Client::run(){
	
	this->init();

	while(acquireControls()){
		
		updateDisplay();
	}	
}

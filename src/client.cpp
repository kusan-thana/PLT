#include "client.hpp"

#include "tileSet1.hpp"
#include "tileSet2.hpp"
#include "tileSet3.hpp"

#include "engine.hpp" //A supprimer après parallélisme (?)
/**
 * Client Class
**/

using namespace client;

Client::Client() : engine(levelState) {
	
	this->tileSets.push_back(new render::TileSet1()); 	//GRID_LAYER			Seriously??
	this->tileSets.push_back(new render::TileSet3());	//CURSORS_LAYER         Seriously??
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
		engine.update();
		updateDisplay();
	}	
}

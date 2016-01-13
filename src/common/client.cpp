#include "client.hpp"
#include <iostream>

#include "render.hpp"
#include "guiRender.hpp"
#include "engine.hpp" //A supprimer apres parallelisme (?)
#include "server.hpp"
//~ #include <X11/Xlib.h>
/**
 * Client Class
**/

using namespace client;

Client::Client(server::Server& serv) :serv(serv), engine(serv.getEngine()), levelState(serv.getLevelState()), gui(levelState, engine, serv),dumbAI(levelState), heuristicAi(levelState){
	
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
    std::cout << "Enregistrement Observer" << std::endl;
    serv.registerObserver(this); 
}
void Client::run(){
	
	Client::init();
	this->init();

	while(acquireControls()){
		serv.getEngine().getUpdateMutex().lock();
		updateDisplay();
		serv.getEngine().getUpdateMutex().unlock();
	}
	serv.join();
}
void Client::serverChanged(const server::ServerEvent& e){
	
	if(e == server::STATE_CHANGED){
		
		//process....
	}
	else if(e == server::INVALID){
		
		//process....
	}	
}

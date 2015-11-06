#include "sfmlClient.hpp"
#include <iostream>
#include <fstream>

#include "elementFactory.hpp"
#include "elementAlloc.hpp"
#include "elementList.hpp"
#include "space.hpp"
#include "obstacle.hpp"
#include "levelState.hpp"
#include "levelStateEvent.hpp"
#include "layer.hpp"
#include "surface.hpp"
#include "tileSet1.hpp"
#include "elementListLayer.hpp"
#include "observable.hpp"
#include "playerCharacter.hpp"
#include "element.hpp"
#include "tileSet2.hpp"
#include "levelListEvent.hpp"


/**
 * Client SFMLClass
**/

using namespace client;

SFMLClient::SFMLClient() : window(sf::VideoMode(1024, 512), "Fantasy World!") {
	
	this->surfaces.push_back(new SFMLSurface());	//GRID_LAYER
	this->surfaces.push_back(new SFMLSurface());	//CHARACTERS_LAYER
	this->surfaces.push_back(new SFMLSurface());	//STATE_LAYER
}
void SFMLClient::init(){

	/*************FACTORY*************/
	state::ElementFactory factory;

	factory.registerType('0', new state::ElementAlloc <state::Space, SpaceTypeID>(GRASS));
	factory.registerType('1', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(WATER));
	factory.registerType('2', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(TREE));
	factory.registerType('3', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(FIR));
	factory.registerType('H', new state::ElementAlloc <state::PlayerCharacter, TypeID>(HERO));
	/*********************************/
	
	state::LevelState levelState;
	levelState.setElementFactory(&factory);
	
	/*************GRID_LAYER*************/
	levelState.loadLevel("../res/stateLevel.txt");
	
	//~ render::ElementListLayer* layer = new render::ElementListLayer();
	render::ElementListLayer layerGrid;
	layerGrid.setSurface(this->surfaces[render::GRID_LAYER]);
	
	//~ render::TileSet1* tileSet = new render::TileSet1();
	render::TileSet1 tileSet;
	setTileSet(render::GRID_LAYER, &tileSet);
	layerGrid.setTileSet(this->tileSets[render::GRID_LAYER]);
	
	scene.setLayer(render::GRID_LAYER, &layerGrid);
	/************************************/
	
	/*************CHARACTERS_LAYER*************/
	state::Element* hero = factory.newInstance('H');	//Instanciation d'un nouvel élément
	hero->setX(10);
	hero->setY(10);
	state::ElementList elementList(levelState);
	elementList.setElement(0, hero);
	
	render::ElementListLayer layerCharacters;
	layerCharacters.setSurface(this->surfaces[render::CHARACTERS_LAYER]);
	
	render::TileSet2 tileSet2;
	setTileSet(render::CHARACTERS_LAYER, &tileSet2);
	layerCharacters.setTileSet(this->tileSets[render::CHARACTERS_LAYER]);
	
	scene.setLayer(render::CHARACTERS_LAYER, &layerCharacters);
	/******************************************/

	state::LevelStateEvent levelStateEvent(levelState, ALL_CHANGED);
	//~ state::Observable observable;
	levelState.registerObserver(&scene);
	levelState.notifyObservers(levelStateEvent);
	
	//~ state::ElementGrid elementGrid = levelState.getElementGrid(); 
	//~ state::ElementList elementList2 = levelState.getElementList(); 
	//~ state::LevelListEvent levelListEvent(elementGrid,0);
	
	//~ levelState.notifyObservers(levelListEvent);

}
bool SFMLClient::acquireControls(){
	
	sf::Event event;
	
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		this->window.close();
	}
	
	return this->window.isOpen();
}
void SFMLClient::updateDisplay(){

	this->window.clear();
	this->window.draw(*((SFMLSurface*)surfaces[render::GRID_LAYER]));
	this->window.display();
}

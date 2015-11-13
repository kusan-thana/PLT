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
#include "tileSet3.hpp"

#include "activateCommand.hpp"
 
/**
 * Client SFMLClass
**/

using namespace client;

SFMLClient::SFMLClient() : window(sf::VideoMode(1024, 512), "Fantasy World!") {
	
	this->surfaces.push_back(new SFMLSurface());	//GRID_LAYER
	this->surfaces.push_back(new SFMLSurface());	//CURSORS_LAYER
	this->surfaces.push_back(new SFMLSurface());	//CHARACTERS_LAYER
}
void SFMLClient::init(){

	/*************FACTORY*************/
	state::ElementFactory* factory = new state::ElementFactory();

	factory->registerType('0', new state::ElementAlloc <state::Space, SpaceTypeID>(GRASS));
	factory->registerType('1', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(WATER));
	factory->registerType('2', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(TREE));
	factory->registerType('3', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(FIR));
	factory->registerType('H', new state::ElementAlloc <state::PlayerCharacter, TypeID>(HERO));
	factory->registerType('R', new state::ElementAlloc <state::Space, SpaceTypeID>(RED));
	factory->registerType('Y', new state::ElementAlloc <state::Space, SpaceTypeID>(YELLOW));
	factory->registerType('G', new state::ElementAlloc <state::Space, SpaceTypeID>(GREEN));
	/*********************************/
	
	levelState.setElementFactory(factory);
	
	/*************GRID_LAYER*************/
	levelState.loadLevel("../res/level1.txt");
	
	render::ElementListLayer* layerGrid = new render::ElementListLayer();
	layerGrid->setSurface(this->surfaces[render::GRID_LAYER]);
	
	layerGrid->setTileSet(this->tileSets[render::GRID_LAYER]);
	
	scene.setLayer(render::GRID_LAYER, layerGrid);
	/************************************/
	
	/*************CHARACTERS_LAYER*************/
	state::Element* hero = factory->newInstance('H');	//Instanciation d'un nouvel élément
	hero->setX(7);
	hero->setY(17);
	state::ElementList& characters = levelState.getElementList();
	characters.setElement(0, hero);
			
	render::ElementListLayer* layerCharacters = new render::ElementListLayer();;
	layerCharacters->setSurface(this->surfaces[render::CHARACTERS_LAYER]);
	
	layerCharacters->setTileSet(this->tileSets[render::CHARACTERS_LAYER]);
	
	scene.setLayer(render::CHARACTERS_LAYER, layerCharacters);
	/******************************************/
	
	/*************CURSOR_LAYER*************/
	state::Element* red = factory->newInstance('R');
	red->setX(7);
	red->setY(19);
	state::ElementList& cursors = levelState.getElementCursors();
	cursors.setElement(0, red);
	
	render::ElementListLayer* layerCursors = new render::ElementListLayer();
	layerCursors->setSurface(this->surfaces[render::CURSORS_LAYER]);
	
	layerCursors->setTileSet(this->tileSets[render::CURSORS_LAYER]);
	
	scene.setLayer(render::CURSORS_LAYER, layerCursors);
	/**************************************/

	state::ElementGrid elementGrid = levelState.getElementGrid();
	elementGrid.registerObserver(layerGrid);
	elementGrid.notifyObservers(-1,-1);
		
	state::ElementList charactersList = levelState.getElementList();
	charactersList.registerObserver(layerCharacters);
	charactersList.notifyObservers(-1);
	
	state::ElementList& cursorsList = levelState.getElementCursors();
	cursorsList.registerObserver(layerCursors);
	cursorsList.notifyObservers(-1);
	
	cursors.getElement(0)->setY(10);
	cursorsList.notifyObservers(0);
}
bool SFMLClient::acquireControls(){
	
	sf::Event event;

	while (this->window.pollEvent(event))
	{
		
		if (event.type == sf::Event::Closed)
		this->window.close();
		
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

			engine.addCommand(new engine::ActivateCommand(state::WEST));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			engine.addCommand(new engine::ActivateCommand(state::NORTH));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			engine.addCommand(new engine::ActivateCommand(state::SOUTH));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			engine.addCommand(new engine::ActivateCommand(state::EAST));
		}

	}

	return this->window.isOpen();
}
void SFMLClient::updateDisplay(){

	this->window.clear();
	this->window.draw(*((SFMLSurface*)surfaces[render::GRID_LAYER]));
	this->window.draw(*((SFMLSurface*)surfaces[render::CURSORS_LAYER]));
	this->window.draw(*((SFMLSurface*)surfaces[render::CHARACTERS_LAYER]));
	this->window.display();
}

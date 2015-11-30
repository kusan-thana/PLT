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
#include "elementListLayer.hpp"
#include "observable.hpp"
#include "playerCharacter.hpp"
#include "element.hpp"
#include "levelListEvent.hpp"
#include "monster.hpp"
#include "cursor.hpp"
#include "guiLayer.hpp"
#include "pathMap.hpp"
#include "guiMoveRange.hpp"
#include "guiTile.hpp"

/**
 * Client SFMLClass
**/

using namespace client;

SFMLClient::SFMLClient() : window(sf::VideoMode(1024, 512), "Fantasy World!") {
	
	this->surfaces.push_back(new SFMLSurface());	//GRID_LAYER
	this->surfaces.push_back(new SFMLSurface());	//MOVE_RANGE_LAYER
	this->surfaces.push_back(new SFMLSurface());	//CURSORS_LAYER
	this->surfaces.push_back(new SFMLSurface());	//TILE_LIST_LAYER
	this->surfaces.push_back(new SFMLSurface());	//CHARACTERS_LAYER
}
void SFMLClient::init(){
	
	/************TEXT*********************/
	// Declare and load a font

	font.loadFromFile("../res/font/theminion.otf");
	text.setFont(font);
	text.setString("Select and move the hero with the cursor");
	text.setCharacterSize(15);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);
	/*************************************/
	
	/*************FACTORY*************/
	state::ElementFactory* factory = new state::ElementFactory();

	factory->registerType('0', new state::ElementAlloc <state::Space, SpaceTypeID>(GRASS));
	factory->registerType('1', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(WATER));
	factory->registerType('2', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(TREE));
	factory->registerType('3', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(FIR));
	factory->registerType('H', new state::ElementAlloc <state::PlayerCharacter, state::TypeId>(state::HERO));
	factory->registerType('W', new state::ElementAlloc <state::PlayerCharacter, state::TypeId>(state::WIZARD));
	factory->registerType('M', new state::ElementAlloc <state::Monster, state::TypeId>(state::MINION));
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
	state::ElementList& characters = levelState.getElementList();
	
	state::Element* hero = factory->newInstance('H');	//Instanciation d'un nouvel élément
	hero->setX(6);
	hero->setY(15);
	characters.setElement(0, hero);
	
	state::Element* wizard1 = factory->newInstance('W');	//Instanciation d'un nouvel élément
	wizard1->setX(5);
	wizard1->setY(15);
	characters.setElement(1, wizard1);
		
	state::Element* wizard2 = factory->newInstance('W');	//Instanciation d'un nouvel élément
	wizard2->setX(7);
	wizard2->setY(15);
	characters.setElement(2, wizard2);
	
	state::Element* minion1 = factory->newInstance('M');	//Instanciation d'un nouvel élément
	minion1->setX(5);
	minion1->setY(19);
	characters.setElement(3, minion1);
	
	state::Element* minion2 = factory->newInstance('M');	//Instanciation d'un nouvel élément
	minion2->setX(6);
	minion2->setY(19);
	characters.setElement(4, minion2);
	
	state::Element* minion3 = factory->newInstance('M');	//Instanciation d'un nouvel élément
	minion3->setX(7);
	minion3->setY(19);
	characters.setElement(5, minion3);
	
	
	ai::PathMap pathMap(levelState);
	pathMap.addElement(minion1);
	pathMap.dijsktra();
	//~ pathMap.computeWeights(levelState.getElementGrid(), wizard);
	pathMap.display();
	pathMap.addElement(minion2);
	pathMap.addElement(minion3);
	pathMap.dijsktra();
	pathMap.display();

	render::ElementListLayer* layerCharacters = new render::ElementListLayer();
	layerCharacters->setSurface(this->surfaces[render::CHARACTERS_LAYER]);
	layerCharacters->setTileSet(this->tileSets[render::CHARACTERS_LAYER]);
	
	scene.setLayer(render::CHARACTERS_LAYER, layerCharacters);
	/******************************************/
	
	/*************GUI::CURSOR_LAYER*************/
	gui::Cursor* cursor = (gui::Cursor*)gui.getCursorList().getGuiElement(0);

	guiRender::GUILayer* layerCursors = new guiRender::GUILayer();
	layerCursors->setSurface(this->surfaces[render::CURSORS_LAYER]);
	
	layerCursors->setTileSet(this->tileSets[render::CURSORS_LAYER]);
	/*******************************************/
	
	/*************GUI::RANGE_LAYER*************/
	gui::GUIMoveRange& moveRange = gui.getMoveRange();

	guiRender::GUILayer* layerMoveRange = new guiRender::GUILayer();
	layerMoveRange->setSurface(this->surfaces[render::MOVE_RANGE_LAYER]);
	
	layerMoveRange->setTileSet(this->tileSets[render::MOVE_RANGE_LAYER]);
	/******************************************/
	
	/*************GUI::ACTIVE_LAYER*************/
	render::ElementListLayer* layerHealthBar = new render::ElementListLayer();
	//~ gui::GUIElementList& healthBar = gui.getHealthBarList();
	//~ tileList.setGuiElement(0, new gui::GUITile(0,0,gui::GUITypeId::ACTIVE_TILE));
	//~ tileList.setGuiElement(1, new gui::GUITile(0,0,gui::GUITypeId::ACTIVE_TILE));
	//~ tileList.setGuiElement(2, new gui::GUITile(0,0,gui::GUITypeId::ACTIVE_TILE));
	
	//~ guiRender::GUILayer* layerTileList = new guiRender::GUILayer();
	layerHealthBar->setSurface(this->surfaces[render::TILE_LIST_LAYER]);
	
	layerHealthBar->setTileSet(this->tileSets[render::TILE_LIST_LAYER]);
	/******************************************/
	
	state::ElementGrid& elementGrid = levelState.getElementGrid();
	elementGrid.registerObserver(layerGrid);
	elementGrid.notifyObservers(-1,-1);
		
	state::ElementList& charactersList = levelState.getElementList();
	charactersList.registerObserver(layerCharacters);
	//~ charactersList.registerObserver(layerHealthBar);
	charactersList.notifyObservers(-1);

	gui::GUIElementList& guiElementList = gui.getCursorList();
	guiElementList.registerObserver(layerCursors);
	guiElementList.notifyObservers(-1);
	
	moveRange.registerObserver(layerMoveRange);
	
	//~ healthBar.registerObserver(layerTileList);
	//~ gui.updateHealthBarList();
	//~ healthBar.update();
	//~ healthBar.notifyObservers(-1);
}
bool SFMLClient::acquireControls() {

	sf::Event event;

	while (this->window.pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
			this->window.close();

		gui::Cursor* cursor = (gui::Cursor*)gui.getCursorList().getGuiElement(0);

		if (event.type == sf::Event::MouseMoved){
			cursor->setY(sf::Mouse::getPosition(window).x * levelState.getElementGrid().getWidth() / window.getSize().x); //Merci benoit pour avoir inverser les axes x et y !
			cursor->setX(sf::Mouse::getPosition(window).y * levelState.getElementGrid().getHeight() / window.getSize().y); //Merci benoit pour avoir inverser les axes x et y !
		}
		else if (event.type == sf::Event::MouseButtonReleased || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)) {
			cursor->setActive(!cursor->getActive());
			//~ if(cursor->getActive()//////////	
			gui.commander(engine);
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {

			std::cout << "Recording started\n";
			gui.setEngineMode(engine::RECORD);
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {

			std::cout << "Replay\n";
			gui.setEngineMode(engine::REPLAY);

		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			cursor->setY(cursor->getY() + 1);
			cursor->setX(cursor->getX() - 1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			cursor->setY(cursor->getY() - 1);
			cursor->setX(cursor->getX() - 1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			cursor->setY(cursor->getY() + 1);
			cursor->setX(cursor->getX() + 1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			cursor->setY(cursor->getY() - 1);
			cursor->setX(cursor->getX() + 1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			cursor->setX(cursor->getX() + 1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			cursor->setY(cursor->getY() + 1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			cursor->setY(cursor->getY() - 1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			cursor->setX(cursor->getX() - 1);
		}
		
		//~ gui.getHealthBarList().notifyObservers(-1);		
		gui.getCursorList().notifyObservers(-1); //On met a jour le GUI a chaque changement d etat du gui
	}		
	return this->window.isOpen();
}
void SFMLClient::updateDisplay(){
	this->window.clear();
	this->window.draw(*((SFMLSurface*)surfaces[render::GRID_LAYER]));
	this->window.draw(*((SFMLSurface*)surfaces[render::MOVE_RANGE_LAYER]));
	this->window.draw(*((SFMLSurface*)surfaces[render::CURSORS_LAYER]));
	this->window.draw(*((SFMLSurface*)surfaces[render::TILE_LIST_LAYER]));
	this->window.draw(*((SFMLSurface*)surfaces[render::CHARACTERS_LAYER]));
	//~ this->window.draw(text);///////////////////////////////////////////////////////////////////////////
	this->window.display();
}

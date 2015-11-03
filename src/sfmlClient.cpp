#include "sfmlClient.hpp"
#include <iostream>
#include <fstream>

#include "elementFactory.hpp"
#include "elementAlloc.hpp"
#include "elementList.hpp"
#include "element.hpp"
#include "space.hpp"
#include "obstacle.hpp"
#include "levelState.hpp"
#include "elementGrid.hpp"
#include "levelStateEvent.hpp"
#include "layer.hpp"
#include "staticTile.hpp"
#include "surface.hpp"
#include "tileSet.hpp"
#include "elementListLayer.hpp"



/**
 * Client SFMLClass
**/

using namespace client;

SFMLClient::SFMLClient() : window(sf::VideoMode(1024, 512), "Fantasy World!") {
}
void SFMLClient::init(){

	/*************FACTORY*************/
	state::ElementFactory factory;

	factory.registerType('0', new state::ElementAlloc <state::Space, SpaceTypeID>(GRASS));
	factory.registerType('1', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(WATER));
	factory.registerType('2', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(TREE));
	factory.registerType('3', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(FIR));

	/*********************************/
	this->sfmlSurfaces.push_back(new SFMLSurface());

	this->sfmlSurfaces[0]->loadTexture("../res/images/dungeon.gif");
	this->sfmlSurfaces[0]->setSpriteCount(512);

	render::TileSet tileSet;

	render::StaticTile tileTree(160,128,32,32);
	tileSet.setStaticTile(tileTree);
	render::StaticTile tileWater(160,160,32,32);
	tileSet.setStaticTile(tileWater);
	render::StaticTile tileGrass(0,160,32,32);
	tileSet.setStaticTile(tileGrass);
	render::StaticTile tileFir(224,128,32,32);
	tileSet.setStaticTile(tileFir);

	//render::Layer layer;
	render::ElementListLayer elementListLayer; 
	elementListLayer.setSurface(sfmlSurfaces[0]);
	elementListLayer.setTileSet(&tileSet);

	scene.setLayer(&elementListLayer);

    int width = 32;
    int height = 16;

    char stateLevel[16*32];
	std::ifstream file("../res/stateLevel.txt", std::ios::in);

	if(file)
	{
		char buf;
		int i =0;
		while(file.get(buf)){

			if (buf !='\n'){
				stateLevel[i] = buf;
				//std::cout << stateLevel[i];
				++i;
			}
		}
		//std::cout << std::endl;
		file.close();
	}
	else
		std::cerr << "Failed to open the file!" << std::endl;

	state::LevelState levelState;
	//levelState.setElementFactory(&factory);
	//levelState.loadLevel("../res/stateLevel.txt");

	state::ElementGrid elementGrid = levelState.getElementGrid();
	//state::ElementList characters = levelState.getCharacters();
	
	//state::LevelStateEvent levelStateEvent(levelState, ALL_CHANGED);
	//scene.levelStateChanged(levelStateEvent);
	

    for (unsigned int i = 0; i < height; ++i)
	{
			for (unsigned int j = 0; j < width; ++j)
			{
				switch(stateLevel[j+i*width]){
					case('0'):
					{
						state::Element* grassElem = factory.newInstance('0');	//Instanciation d'un nouvel élément
						elementGrid.setElement(j+i*width, grassElem);			//Ajout du (j+i*width)ième élément dans la liste d'élément
						sfmlSurfaces[0]->setSpriteTexture(j+i*width, &tileTree);
					}
					break;
					case('1'):
					{
						state::Element* waterElem = factory.newInstance('1');
						elementGrid.setElement(j+i*width, waterElem);
						sfmlSurfaces[0]->setSpriteTexture(j+i*width, &tileWater);
					}
					break;
					case('2'):
					{
						state::Element* treeElem = factory.newInstance('2');
						elementGrid.setElement(j+i*width, treeElem);
						sfmlSurfaces[0]->setSpriteTexture(j+i*width, &tileGrass);
					}
					break;
					case('3'):
					{
						state::Element* firElem = factory.newInstance('3');
						elementGrid.setElement(j+i*width, firElem);
						sfmlSurfaces[0]->setSpriteTexture(j+i*width, &tileFir);
					}
					break;
				}
				sfmlSurfaces[0]->setSpriteLocation(j+i*width,j*32,i*32);	
			}
	}
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
	this->window.draw(*sfmlSurfaces[0]);
	this->window.display();
}

#include "sfmlClient.hpp"
#include <iostream>
#include <fstream>

#include "elementFactory.hpp"
#include "elementAlloc.hpp"
#include "elementList.hpp"
#include "element.hpp"
#include "space.hpp"
#include "obstacle.hpp"

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

	render::Layer layer;
	layer.setSurface(sfmlSurfaces[0]);
	layer.setTileSet(&tileSet);

	scene.setLayer(&layer);

    int width = 32;
    int height = 16;

    //~ const int etat[] = {
        //~ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        //~ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        //~ 1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        //~ 0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        //~ 0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        //~ 0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        //~ 2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        //~ 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        //~ 0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        //~ 2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        //~ 0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        //~ 0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        //~ 0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        //~ 1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        //~ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        //~ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    //~ };

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

	state::ElementList elementList;

    for (unsigned int j = 0; j < height; ++j)
	{
			for (unsigned int i = 0; i < width; ++i)
			{
				switch(stateLevel[i+j*width]){
					case('0'):
					{
						state::Element* grassElem = factory.newInstance('0');	//Instanciation d'un nouvel élément
						elementList.setElement(i+j*width, grassElem);			//Ajout du (i+j*width)ième élément dans la liste d'élément
						sfmlSurfaces[0]->setSpriteTexture(i+j*width, &tileTree);
					}
					break;
					case('1'):
					{
						state::Element* waterElem = factory.newInstance('1');
						elementList.setElement(i+j*width, waterElem);
						sfmlSurfaces[0]->setSpriteTexture(i+j*width, &tileWater);
					}
					break;
					case('2'):
					{
						state::Element* treeElem = factory.newInstance('2');
						elementList.setElement(i+j*width, treeElem);
						sfmlSurfaces[0]->setSpriteTexture(i+j*width, &tileGrass);
					}
					break;
					case('3'):
					{
						state::Element* firElem = factory.newInstance('3');
						elementList.setElement(i+j*width, firElem);
						sfmlSurfaces[0]->setSpriteTexture(i+j*width, &tileFir);
					}
					break;
				}
				sfmlSurfaces[0]->setSpriteLocation(i+j*width,i*32,j*32);	
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

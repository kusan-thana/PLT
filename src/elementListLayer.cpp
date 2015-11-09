#include "levelState.hpp" //forward dependency
#include "elementListLayer.hpp"
#include "elementGrid.hpp"
#include "elementList.hpp"
#include "element.hpp"
#include "obstacle.hpp"
#include "sfmlSurface.hpp"

#include "tileSet1.hpp"
#include "tileSet2.hpp"
#include "tile.hpp"
#include "staticTile.hpp"
#include "scene.hpp"
#include "levelListEvent.hpp"
#include <iostream>
/**
 * ElementListLayer Class
**/

using namespace render;

void ElementListLayer::update(const state::ElementList& elementList, int i){

	if(i == render::GRID_LAYER)
	{
		//~ std::cout << "ElementListLayer : GRID_LAYER" << std::endl;
		const state::ElementGrid& grid = static_cast<const state::ElementGrid&>(elementList);
		int width = grid.getWidth();
		int height = grid.getHeight();
		
		int widthCell = (this->tileSet)->getCellWidth();
		int heigthCell = (this->tileSet)->getCellHeight();
		
		(this->surface)->loadTexture((this->tileSet)->getImageFile());
		(this->surface)->setSpriteCount(width*height);
	
		for(int j = 0; j < elementList.size(); j++){
			
		state::Element* curr_elem = elementList.getElement(j);
		int x = curr_elem->getX();
		int y = curr_elem->getY();

		const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);		//Add cast TileSet1 ???? (Presently, no matter because there is just one TileSet1 but when several TileSet'X' ??)
		
		(this->surface)->setSpriteTexture(y+x*width, (StaticTile*)curr_tile);
		(this->surface)->setSpriteLocation(y+x*width, y*widthCell, x*heigthCell);	
		}
	}
	if(i == render::CHARACTERS_LAYER)
	{
		std::cout << "ElementListLayer : CHARACTERS_LAYER" << std::endl;
		//const state::ElementGrid& grid = static_cast<const state::ElementGrid&>(elementList);
		//~ int width = grid.getWidth();
		//~ int height = grid.getHeight();
		int width = 32;		//awful..
		int height = 16;	//awful..
		
		int widthCell = (this->tileSet)->getCellWidth();
		int heigthCell = (this->tileSet)->getCellHeight();
		std::cout << "widthCell : " << widthCell << std::endl;
		std::cout << "heigthCell : " << heigthCell << std::endl;
		
		//~ (this->surface)->loadTexture(((render::TileSet2*)(this->tileSet))->getImageFile());
		(this->surface)->loadTexture((this->tileSet)->getImageFile());
		std::cout << (this->tileSet)->getImageFile() << std::endl;
		(this->surface)->setSpriteCount(512);		//Think about it..
	
		std::cout << "elementList.size : " << elementList.size() << std::endl;
	
		for(int j = 0; j < elementList.size(); j++){
		
		std::cout << "Check" << std::endl;
		std::cout << "elementList.size : " << elementList.size() << std::endl;
		state::Element* curr_elem = elementList.getElement(j);
		int x = curr_elem->getX();
		int y = curr_elem->getY();
		std::cout << "Check2" << std::endl;
		const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);		//Add cast TileSet2 ???? 
		std::cout << "Check3" << std::endl;
		(this->surface)->setSpriteTexture(y+x*width, (StaticTile*)curr_tile);		//Use width and height of GRID, may have some problemes if CHARACTERS and GRID have not the same size... (boundary right and bottom)
		(this->surface)->setSpriteLocation(y+x*width, y*widthCell, x*heigthCell);
		}
	}
}
void ElementListLayer::levelStateChanged(const state::LevelStateEvent& e){
	
	//~ state::ElementGrid grid = e.levelState.getElementGrid();
	//~ int width = grid.getWidth();
	//~ int height = grid.getHeight();
	
	//~ int widthCell = (this->tileSet)->getCellWidth();
	//~ int heigthCell = (this->tileSet)->getCellHeight();
	
	//~ (this->surface)->loadTexture((this->tileSet)->getImageFile());
	//~ (this->surface)->setSpriteCount(width*height);
	
	//~ for(int i = 0; i < grid.size(); i++)
	//~ {
		//~ state::Element* curr_elem = grid.getElement(i);
		//~ int x = curr_elem->getX();
		//~ int y = curr_elem->getY();
//~ 
		//~ const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);		//Add cast TileSet'X' ???? 
		//~ 
		//~ (this->surface)->setSpriteTexture(y+x*width, (StaticTile*)curr_tile);
		//~ (this->surface)->setSpriteLocation(y+x*width, y*widthCell, x*heigthCell);	
	//~ 
	//~ }
	const state::LevelListEvent& levelListEvent = static_cast<const state::LevelListEvent&>(e);
	update(levelListEvent.list, levelListEvent.idx);
}

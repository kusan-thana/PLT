#include "levelState.hpp" //forward dependency
#include "elementListLayer.hpp"
#include "elementGrid.hpp"
#include "elementList.hpp"
#include "element.hpp"
#include "obstacle.hpp"
#include "sfmlSurface.hpp"

#include "tileSet1.hpp"
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
		for(int j = 0; i < elementList.size(); i++){
			
		//~ state::Element* curr_elem = grid.getElement(i);
		//~ int x = curr_elem->getX();
		//~ int y = curr_elem->getY();
//~ 
		//~ const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);		//Add cast TileSet1 ???? (Presently, no matter because there is just one TileSet1 but when several TileSet'X' ??)
		//~ 
		//~ (this->surface)->setSpriteTexture(y+x*width, (StaticTile*)curr_tile);
		//~ (this->surface)->setSpriteLocation(y+x*width, y*widthCell, x*heigthCell);	
		}
	}
}
void ElementListLayer::levelStateChanged(const state::LevelStateEvent& e){
	
	state::ElementList elementList = e.levelState.getElementList();

	state::ElementGrid grid = e.levelState.getElementGrid();
	int width = grid.getWidth();
	int height = grid.getHeight();
	
	int widthCell = (this->tileSet)->getCellWidth();
	int heigthCell = (this->tileSet)->getCellHeight();
	
	(this->surface)->loadTexture((this->tileSet)->getImageFile());
	(this->surface)->setSpriteCount(width*height);
	
	for(int i = 0; i < grid.size(); i++)
	{
		state::Element* curr_elem = grid.getElement(i);
		int x = curr_elem->getX();
		int y = curr_elem->getY();

		const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);		//Add cast TileSet1 ???? (Presently, no matter because there is just one TileSet1 but when several TileSet'X' ??)
		
		(this->surface)->setSpriteTexture(y+x*width, (StaticTile*)curr_tile);
		(this->surface)->setSpriteLocation(y+x*width, y*widthCell, x*heigthCell);	
	
	}
	//update(e.list, e.idx);
}

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

	int widthCell = (this->tileSet)->getCellWidth();
	int heigthCell = (this->tileSet)->getCellHeight();
	
	(this->surface)->loadTexture((this->tileSet)->getImageFile());
	(this->surface)->setSpriteCount(elementList.size());
	
	if(i<0)	{
		for(int j = 0; j < elementList.size(); j++){
			
		state::Element* curr_elem = elementList.getElement(j);
		int x = curr_elem->getX();
		int y = curr_elem->getY();

		const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);
		
		(this->surface)->setSpriteTexture(j, (StaticTile*)curr_tile);
		(this->surface)->setSpriteLocation(j, y*widthCell, x*heigthCell);
		}
	}
	if(i>=0)
	{
		state::Element* curr_elem = elementList.getElement(i);
		int x = curr_elem->getX();
		int y = curr_elem->getY();
		
		const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);

		(this->surface)->setSpriteTexture(i, (StaticTile*)curr_tile);
		(this->surface)->setSpriteLocation(i, y*widthCell, x*heigthCell);
	}
}
void ElementListLayer::levelStateChanged(const state::LevelStateEvent& e){
	
	const state::LevelListEvent& levelListEvent = static_cast<const state::LevelListEvent&>(e);
	update(levelListEvent.list, levelListEvent.idx);
}

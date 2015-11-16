#include "ihmLayer.hpp"
#include <iostream>
#include "staticTile.hpp"

/**
 * IHMLayer Class
**/

using namespace ihmRender;

IHMLayer::IHMLayer() {
}
IHMLayer::~IHMLayer(){
}
const render::TileSet* IHMLayer::getTileSet() const{

	return tileSet;
}
void IHMLayer::setTileSet(const render::TileSet* tileSet){
	
	this->tileSet = tileSet;
}
void IHMLayer::setSurface(Surface* surface){
	
	this->surface = surface;
}

//~ void ElementListLayer::update(const state::ElementList& elementList, int i){
//~ 
	//~ int widthCell = (this->tileSet)->getCellWidth();
	//~ int heigthCell = (this->tileSet)->getCellHeight();
	//~ 
	//~ (this->surface)->loadTexture((this->tileSet)->getImageFile());
	//~ (this->surface)->setSpriteCount(elementList.size());
	//~ 
	//~ if(i<0)	{
		//~ for(int j = 0; j < elementList.size(); j++){
			//~ 
		//~ state::Element* curr_elem = elementList.getElement(j);
		//~ int x = curr_elem->getX();
		//~ int y = curr_elem->getY();
//~ 
		//~ const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);
		//~ 
		//~ (this->surface)->setSpriteTexture(j, (StaticTile*)curr_tile);
		//~ (this->surface)->setSpriteLocation(j, y*widthCell, x*heigthCell);
		//~ }
	//~ }
	//~ if(i>=0)
	//~ {
		//~ state::Element* curr_elem = elementList.getElement(i);
		//~ int x = curr_elem->getX();
		//~ int y = curr_elem->getY();
		//~ 
		//~ const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);
//~ 
		//~ (this->surface)->setSpriteTexture(i, (StaticTile*)curr_tile);
		//~ (this->surface)->setSpriteLocation(i, y*widthCell, x*heigthCell);
	//~ }
//~ }
void IHMLayer::ihmChanged(const ihm::IHMEvent& e){
	
	int widthCell = (this->tileSet)->getCellWidth();
	int heigthCell = (this->tileSet)->getCellHeight();
	
	(this->surface)->loadTexture((this->tileSet)->getImageFile());
	(this->surface)->setSpriteCount(1);		//size function to define ?
	
	
	int x = e.cursor.getX();
	int y = e.cursor.getY();
	
	const render::Tile* curr_tile =	new render::StaticTile(0,0,32,32);
	//~ const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);		//Need to code TileSet class for IHM
	//~ 
	(this->surface)->setSpriteTexture(0, (render::StaticTile*)curr_tile);
	(this->surface)->setSpriteLocation(0, y*widthCell, x*heigthCell);

}

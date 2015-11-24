#include "guiLayer.hpp"
#include <iostream>
#include "staticTile.hpp"
#include "cursor.hpp"
#include "guiMoveRange.hpp"
#include "mobileElement.hpp"
#include "guiElement.hpp"
#include "elementGrid.hpp"

/**
 * GUILayer Class
**/

using namespace guiRender;

GUILayer::GUILayer() {
}
GUILayer::~GUILayer(){
}
const render::TileSet* GUILayer::getTileSet() const{

	return tileSet;
}
void GUILayer::setTileSet(const render::TileSet* tileSet){
	
	this->tileSet = tileSet;
}
void GUILayer::setSurface(Surface* surface){
	
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

void GUILayer::update(gui::GUIElementList& guiElementList, int i){
	
	gui::GUI gui = guiElementList.getGui();
	gui::Cursor* cursor = (gui::Cursor*)gui.getCursorList().getGuiElement(0);
	state::ElementGrid grid = gui.getLevelState().getElementGrid();
	state::ElementList characters = gui.getLevelState().getElementList();
	
	
	int widthCell = (this->tileSet)->getCellWidth();
	int heigthCell = (this->tileSet)->getCellHeight();
	
	(this->surface)->loadTexture((this->tileSet)->getImageFile());
	(this->surface)->setSpriteCount(guiElementList.size());
	
	if(i<0)	{
		for(int j = 0; j < guiElementList.size(); j++){

			gui::GUIElement* curr_guiElem = guiElementList.getGuiElement(j);
			int x = curr_guiElem->getX();
			int y = curr_guiElem->getY();
			
			if(curr_guiElem->getGuiTypeId() == gui::GUITypeId::CURSOR){
					if(curr_guiElem->getActive()){
						const render::Tile* curr_tile = new render::StaticTile(32,0,32,32);	//YELLOW
						//~ ////~ const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);		//Need to code TileSet class for GUI
						
						(this->surface)->setSpriteTexture(j, (render::StaticTile*)curr_tile);
						(this->surface)->setSpriteLocation(j, y*widthCell, x*heigthCell);
					}
					else { 
						const render::Tile* curr_tile =	new render::StaticTile(0,0,32,32);	//RED
						(this->surface)->setSpriteTexture(j, (render::StaticTile*)curr_tile);
						(this->surface)->setSpriteLocation(j, y*widthCell, x*heigthCell);
					}
			}
			if(curr_guiElem->getGuiTypeId() == gui::GUITypeId::TILE){
				
				if(x < grid.getHeight() && y < grid.getWidth() && (grid.getCell(x,y)->getTypeID() == state::TypeID::OBSTACLE || characters.getElement(x,y))){
					const render::Tile* curr_tile = new render::StaticTile(0,0,32,32);	//RED
					
					(this->surface)->setSpriteTexture(j, (render::StaticTile*)curr_tile);
					(this->surface)->setSpriteLocation(j, y*widthCell, x*heigthCell);
				}
				else{
					const render::Tile* curr_tile = new render::StaticTile(64,0,32,32);	//GREEN
				//~ //	 const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);		//Need to code TileSet class for GUI
					
					(this->surface)->setSpriteTexture(j, (render::StaticTile*)curr_tile);
					(this->surface)->setSpriteLocation(j, y*widthCell, x*heigthCell);
				}
			}
		}
	}	
}
void GUILayer::guiChanged(const gui::GUIEvent& e){
	
	update(e.guiElementList, e.idx);
}

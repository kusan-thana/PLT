#include "levelState.hpp" //forward dependency
#include "elementListLayer.hpp"
#include "elementGrid.hpp"
#include "element.hpp"
#include "obstacle.hpp"
#include "sfmlSurface.hpp"

#include "tileSet1.hpp"
#include "tile.hpp"
#include "staticTile.hpp"

#include <iostream>
/**
 * ElementListLayer Class
**/

using namespace render;

void ElementListLayer::levelStateChanged(const state::LevelStateEvent& e){
	
		state::ElementGrid grid = e.levelState.getElementGrid();
		int width = grid.getWidth();
		int height = grid.getHeight();
		//~ std::cout << " width = " << width << std::endl;
		//~ std::cout << " height = " << height << std::endl;
		
		this->tileSet = new render::TileSet1();
		int widthCell = (this->tileSet)->getCellWidth();
		int heigthCell = (this->tileSet)->getCellHeight();
		
		this->surface = new SFMLSurface();

		(this->surface)->loadTexture((this->tileSet)->getImageFile());
		
		state::Element* curr_elem = grid.getElement(0);
		
		for(int i = 0; i < grid.size(); i++)
		{
			//state::Element* curr_elem = grid.getElement(i);
			int x = curr_elem->getX();
			int y = curr_elem->getY();
			//~ std::cout << " i = " << i << std::endl;
			//~ std::cout << " x = " << x << std::endl;
			//~ std::cout << " y = " << y << std::endl;
						
			const render::Tile* curr_tile = (this->tileSet)->getElementTile(curr_elem);		//Add cast TileSet1 ????
			
			//~ std::cout << " i = " << i << std::endl;
			//~ std::cout << ((StaticTile*)curr_tile)->getX() << std::endl;
			
			if(curr_elem->getTypeID() == SPACE){
				
			}
			if(curr_elem->getTypeID() == OBSTACLE){
				
				switch(((state::Obstacle*)curr_elem)->getObstacleTypeID())
				{
					case(TREE):
					{
						
						//(this->surface)->setSpriteTexture(y+x*width, (StaticTile*)curr_tile);
						(this->surface)->setSpriteTexture(y+x*width, (StaticTile*)curr_tile);
		
						//~ (this->surface)->setSpriteLocation(y+x*width,y*widthCell,x*heigthCell);		
						(this->surface)->setSpriteLocation(y+x*width,y*widthCell,x*heigthCell);		
					}
					break;
				}
			}
		}
}

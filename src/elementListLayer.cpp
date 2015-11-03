#include "levelState.hpp" //forward dependency
#include "elementListLayer.hpp"
#include "elementGrid.hpp"
#include "element.hpp"
#include "obstacle.hpp"
#include "sfmlSurface.hpp"
/**
 * ElementListLayer Class
**/

using namespace render;

void ElementListLayer::levelStateChanged(const state::LevelStateEvent& e){
	
		//~ const render::TileSet* tileSetGrid = layers[GRID_LAYER]->getTileSet();
		//const render::TileSet* sfmlSurfaces = layers[GRID_LAYER]->getTileSet();
		state::ElementGrid grid = e.levelState.getElementGrid();
		//~ //sfmlSurfaces[0]->setSpriteTexture(j+i*width, &tileTree);
		
		
		int width = grid.getWidth();
		int height = grid.getHeight();
		
		for(int i = 0; i < grid.size(); i++)
		{
			state::Element* curr_elem = grid.getElement(i);
			int x = curr_elem->getX();
			int y = curr_elem->getY();
			
			if(curr_elem->getTypeID() == SPACE){
				
			}
			if(curr_elem->getTypeID() == OBSTACLE){
				
				switch(((state::Obstacle*)curr_elem)->getObstacleTypeID())
				{
					case(TREE):
					{
						//(this->surface)->setSpriteTexture(y+x*width, &tileTree);
					}
					break;
				}
				
			}
		}
}

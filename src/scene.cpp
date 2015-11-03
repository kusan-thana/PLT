#include "scene.hpp"

#include "levelState.hpp"
#include "tileSet.hpp"
#include "elementGrid.hpp"
#include "element.hpp"
#include "obstacle.hpp"
#include "elementListLayer.hpp"
/**
 * Scene Class
**/
enum SceneLayer { GRID_LAYER=0, CHARACTERS_LAYER=1, STATE_LAYER=2 };

using namespace render;

Scene::Scene(){
}
Scene::Scene(int width, int height) : width(width), height(height){
}
Scene::~Scene(){
}
void Scene::setLayer(Layer* layer){

	this->layers.push_back(layer);
}
void Scene::levelStateChanged(const state::LevelStateEvent& e){
	
	state::ElementGrid grid = e.levelState.getElementGrid();
	
	this->width = grid.getWidth();
	this->height = grid.getHeight();
	
	if(e == ALL_CHANGED)
	{
		((render::ElementListLayer*)layers[GRID_LAYER])->levelStateChanged(e);
	
		
		//~ const render::TileSet* tileSetGrid = layers[GRID_LAYER]->getTileSet();
		//~ //const render::TileSet* sfmlSurfaces = layers[GRID_LAYER]->getTileSet();
		//~ //state::ElementGrid grid = e.levelState.getElementGrid();
		//~ //sfmlSurfaces[0]->setSpriteTexture(j+i*width, &tileTree);
		//~ for(int i = 0; i < grid.size(); i++)
		//~ {
			//~ state::Element* curr_elem = grid.getElement(i);
			
			//~ if(curr_elem->getTypeID() == SPACE){
				
				
			//~ }
			//~ if(curr_elem->getTypeID() == OBSTACLE){
				
				//~ switch(((state::Obstacle*)curr_elem)->getObstacleTypeID())
				//~ {
					//~ case(TREE):
					//~ {
						//~ state::Element* grassElem = factory.newInstance('0');	//Instanciation d'un nouvel élément
						//~ elementGrid.setElement(j+i*width, grassElem);			//Ajout du (j+i*width)ième élément dans la liste d'élément
						//sfmlSurfaces[GRID_LAYER]->setSpriteTexture(j+i*width, &tileTree);
						//~ //tileSetGrid;
						//~ layers[GRID_LAYER]->levelStateChanged();
					//~ }
					//~ break;
				//~ }
				
			//~ }
		//~ }
	}
}

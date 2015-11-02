#include "scene.hpp"

#include "levelState.hpp"
#include "tileSet.hpp"
#include "elementGrid.hpp"
#include "element.hpp"
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
	
	if(e == ALL_CHANGED)
	{
		layers[GRID_LAYER]->getTileSet();
		//~ const state::ElementGrid grid = e.levelState.getElementGrid();
		state::ElementGrid grid = e.levelState.getElementGrid();
		//sfmlSurfaces[0]->setSpriteTexture(j+i*width, &tileTree);
		for(int i = 0; i < grid.size(); i++)
		{
			state::Element* curr_elem = grid.getElement(i);
		}
	}
}

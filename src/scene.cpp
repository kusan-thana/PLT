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
		layers.push_back(new ElementListLayer());
		((ElementListLayer*)layers[GRID_LAYER])->levelStateChanged(e);
	}
}

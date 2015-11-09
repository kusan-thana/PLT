#include "scene.hpp"

#include "levelState.hpp"
#include "tileSet.hpp"
#include "elementGrid.hpp"
#include "element.hpp"
#include "obstacle.hpp"
#include "elementListLayer.hpp"
#include "levelListEvent.hpp"

#include <iostream>
/**
 * Scene Class
**/

using namespace render;

Scene::Scene(){
	//~ layers.resize(3);
	layers.push_back(new ElementListLayer());	//GRID_LAYER
	layers.push_back(new ElementListLayer());	//CHARACTERS_LAYER
	layers.push_back(new ElementListLayer());	//STATE_LAYER
}
Scene::~Scene(){
}
void Scene::setLayer(int idx, Layer* layer){

	if(idx == GRID_LAYER)
		this->layers[GRID_LAYER] = layer;
		//~ this->layers[GRID_LAYER].reset(layer);		//Memory leak ??
	
	if(idx == CHARACTERS_LAYER)
		this->layers[CHARACTERS_LAYER] = layer;
	
	if(idx == STATE_LAYER)
		this->layers[STATE_LAYER] = layer;
}
void Scene::levelStateChanged(const state::LevelStateEvent& e){
	
	((ElementListLayer*)layers[GRID_LAYER])->levelStateChanged(e);
	//~ ((ElementListLayer*)layers[CHARACTERS_LAYER])->levelStateChanged(e);
	if(e == ALL_CHANGED)
	{
		//~ ((ElementListLayer*)layers[GRID_LAYER])->levelStateChanged(e);
		//((ElementListLayer*)layers[CHARACTERS_LAYER])->levelStateChanged(e);
	}
}

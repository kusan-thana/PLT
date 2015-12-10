#include "render.hpp"

#include "levelState.hpp"
#include "elementGrid.hpp"
#include "element.hpp"
#include "obstacle.hpp"
#include "levelListEvent.hpp"

#include <iostream>
/**
 * Scene Class
**/

using namespace render;

Scene::Scene(){

	layers.resize(4);	//Allocate an array of size 3 with initialized pointers at NULL (GRID_LAYER, CURSORS_LAYER, CHARACTERS_LAYER) 
}
Scene::~Scene(){
}
void Scene::setLayer(int idx, Layer* layer){

	if(idx == GRID_LAYER)
		this->layers[GRID_LAYER] = layer;				//Memory leak ??
		//~ this->layers[GRID_LAYER].reset(layer);		
	
	if(idx == MOVE_RANGE_LAYER)
		this->layers[MOVE_RANGE_LAYER] = layer;
		
	if(idx == CHARACTERS_LAYER)
		this->layers[CHARACTERS_LAYER] = layer;
}
void Scene::levelStateChanged(const state::LevelStateEvent& e){
	
	//~ ((ElementListLayer*)layers[GRID_LAYER])->levelStateChanged(e);
	//~ ((ElementListLayer*)layers[CHARACTERS_LAYER])->levelStateChanged(e);
	if(e == ALL_CHANGED)
	{
		//~ ((ElementListLayer*)layers[GRID_LAYER])->levelStateChanged(e);
		//((ElementListLayer*)layers[CHARACTERS_LAYER])->levelStateChanged(e);
	}
}

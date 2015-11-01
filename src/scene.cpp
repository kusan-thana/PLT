#include "scene.hpp"
#include <iostream>
/**
 * Scene Class
**/

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

	}
}

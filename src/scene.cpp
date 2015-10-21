#include "scene.hpp"

/**
 * Scene Class
**/

using namespace render;

Scene::Scene(){
}
Scene::Scene(int width, int height) : width(width), height(height){
 
	//layers.push_back(new Layer());
}
Scene::~Scene(){
}
void Scene::setLayer(Layer* layer){

	this->layers.push_back(layer);
}

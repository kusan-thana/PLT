#include "scene.hpp"

/**
 * Scene Class
**/

Scene::Scene(){
}
Scene::~Scene(){
}
void Scene::setLayer(Layer* layer){

	this->layers.push_back(layer);
}

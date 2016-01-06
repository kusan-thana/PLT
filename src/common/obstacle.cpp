#include "state.hpp"

/**
 * Obstacle Class
**/

using namespace state;

Obstacle::Obstacle(ObstacleTypeID id) : IDObstacle(id){
	
	this->IdElement = OBSTACLE;
}
bool Obstacle::isSpace() const{
	
	return false;
}
ObstacleTypeID Obstacle::getObstacleTypeID() const{
	
	return this->IDObstacle;
}
void Obstacle::setObstacleTypeID(ObstacleTypeID id){

	this->IDObstacle = id;
}
Element* Obstacle::clone() const{
	
	Element* clone = new Obstacle(IDObstacle);
	
	((Obstacle*)clone)->IdElement = IdElement;
	((Obstacle*)clone)->x = x;
	((Obstacle*)clone)->y = y;
	((Obstacle*)clone)->active = active;
	((Obstacle*)clone)->orientation = orientation;
	
	return clone;
}

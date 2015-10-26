#include "obstacle.hpp"

/**
 * Obstacle Class
**/

using namespace state;

Obstacle::Obstacle(ObstacleTypeID id) : IDObstacle(id){
	
	this->IDElement = OBSTACLE;
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

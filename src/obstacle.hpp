#ifndef Obstacle_H
#define Obstacle_H
#include "staticElement.hpp"

enum ObstacleTypeID { WALL=1, STONE=2, TREE=3, FIR=3, WATER=4 };

namespace state {
	
class Obstacle : public StaticElement {
	
	protected:
		ObstacleTypeID IDObstacle;
	
	public:
		Obstacle(ObstacleTypeID id);
		virtual bool isSpace() const;
		ObstacleTypeID getObstacleTypeID() const;
		void setObstacleTypeID(ObstacleTypeID id);

};
}
#endif

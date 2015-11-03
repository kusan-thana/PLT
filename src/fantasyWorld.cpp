#include <SFML/Graphics.hpp>
#include <iostream>

#include "client.hpp"
#include "sfmlClient.hpp"
#include "element.hpp"
#include "obstacle.hpp"

#include "levelState.hpp"



using namespace std;

int main()
{
	//state::Obstacle water(WATER);
	//state::Element* element = &water;
	//~ std::cout << element->getTypeID() << std::endl;
	//std::cout << ((state::Obstacle*)element)->getObstacleTypeID() << std::endl;
	//state::LevelState levelState;
	//levelState.loadLevel("../res/stateLevel.txt");
	
    client::Client* client = new client::SFMLClient();

	client->run();
	
    return 0;
}

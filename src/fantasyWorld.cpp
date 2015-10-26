#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

#include "client.hpp"
#include "sfmlclient.hpp"
#include "elementAlloc.hpp"
#include "playerCharacter.hpp"
#include "element.hpp"
#include "elementFactory.hpp"
#include "space.hpp"
#include "obstacle.hpp"


using namespace std;

int main()
{
	/*************FILE*************/
	char stateLevel[16*32];
	ifstream file("../res/stateLevel.txt", ios::in);

	if(file)
	{       
		char buf;
		int i =0;
		while(file.get(buf)){

			if (buf !='\n'){
				stateLevel[i] = buf;
				//cout << stateLevel[i];
				++i;
			}
		}
			
		//cout << endl;
		file.close();
	}
	else
		cerr << "Failed to open the file!" << endl;
	
	/*************FACTORY*************/
	state::ElementFactory factory;
	
	factory.registerType('0', new state::ElementAlloc <state::Space, SpaceTypeID>(GRASS));
	factory.registerType('1', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(WATER));
	factory.registerType('2', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(TREE));
	factory.registerType('3', new state::ElementAlloc <state::Obstacle, ObstacleTypeID>(FIR));
	
	Element* grass = factory.newInstance('0');
	Element* water = factory.newInstance('1');
	Element* tree = factory.newInstance('2');
	Element* fir = factory.newInstance('3');
	
	//~ cout << grass->getTypeID() << endl;
	//~ cout << water->getTypeID() << endl;
	//~ cout << tree->getTypeID() << endl;
	//~ cout << fir->getTypeID() << endl;
	
	
	/*********************************/
		
    Client* client = new SFMLClient();

	client->run();
	
    return 0;
}

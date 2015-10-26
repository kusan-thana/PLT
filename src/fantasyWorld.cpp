#include <SFML/Graphics.hpp>
#include <iostream>

#include "client.hpp"
#include "sfmlclient.hpp"
#include "elementAlloc.hpp"
#include "playerCharacter.hpp"
#include "element.hpp"
#include "elementFactory.hpp"


using namespace std;

int main()
{
	state::ElementFactory factory;
	
	factory.registerType('H', new state::ElementAlloc <PlayerCharacter, TypeID>(HERO));
	
	Element* hero = factory.newInstance('H');
	
	
	
	cout << hero->getTypeID() << endl;
	
    Client* client = new SFMLClient();

	client->run();
	
    return 0;
}


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "client.hpp"
#include "sfmlClient.hpp"
#include "element.hpp"
#include "obstacle.hpp"

#include "levelState.hpp"
#include "tileSet1.hpp"


using namespace std;

int main()
{	
	client::Client* client = new client::SFMLClient();

	client->run();
	
    return 0;
}

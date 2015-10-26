#include <SFML/Graphics.hpp>
#include <iostream>

#include "client.hpp"
#include "sfmlclient.hpp"

using namespace std;

int main()
{

    Client* client = new SFMLClient();

	client->run();
	
    return 0;
}

#include <SFML/Graphics.hpp>
#include <iostream>

#include "client.hpp"
#include "sfmlClient.hpp"


using namespace std;

int main()
{
    client::Client* client = new client::SFMLClient();

	client->run();
	
    return 0;
}

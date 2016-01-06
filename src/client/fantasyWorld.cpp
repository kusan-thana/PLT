
#include <SFML/Graphics.hpp>
#include <iostream>
//#include <vector>

#include "../common/client.hpp"

#include "../common/state.hpp"
#include "../common/render.hpp"


using namespace std;

int main()
{	
	cout << "--------Client--------\n";
	server::Server* server = new server::RemoteServerSFML();
	client::Client* client = new client::SFMLClient(*server);
	
	server->runBackground();
	client->run();
	
    return 0;
}

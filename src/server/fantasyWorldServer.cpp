
#include <SFML/Graphics.hpp>
#include <iostream>
//#include <vector>

#include "../common/client.hpp"

#include "../common/state.hpp"
#include "../common/render.hpp"


using namespace std;

int main()
{	
	cout << "main Server\n";
	server::Server* server = new server::LocalServer();
	client::Client* client = new client::SFMLClient(*server);
	//server::Server* server = new server::LocalServer(); //Pas de parallélisme encore - moteur de jeu instancié dans le client temporairement
	
	server->runBackground();
	client->run();
	//~ server->join();
	
    return 0;
}

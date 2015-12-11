
#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>

#include "client.hpp"

#include "state.hpp"
#include "render.hpp"


using namespace std;

int main()
{	
	server::Server* server = new server::LocalServer();
	client::Client* client = new client::SFMLClient(*server);
	//server::Server* server = new server::LocalServer(); //Pas de parallélisme encore - moteur de jeu instancié dans le client temporairement

	client->run();
	
    return 0;
}

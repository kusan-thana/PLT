
#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>

#include "client.hpp"
#include "server.hpp"
#include "localServer.hpp"

#include "element.hpp"
#include "obstacle.hpp"

#include "levelState.hpp"
#include "render.hpp"


using namespace std;

int main()
{	
	client::Client* client = new client::SFMLClient();
	//server::Server* server = new server::LocalServer(); //Pas de parallélisme encore - moteur de jeu instancié dans le client temporairement

	client->run();
	
    return 0;
}

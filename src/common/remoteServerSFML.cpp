#include "server.hpp"
#include <iostream>
#include <SFML/Network.hpp>

using namespace server;

RemoteServerSFML::RemoteServerSFML(){
}
RemoteServerSFML::~RemoteServerSFML(){
}
void RemoteServerSFML::run(){

    sf::Http::Request request("/user/1", sf::Http::Request::Get);
    sf::Http http("http://localhost/", 8080);
    sf::Http::Response response = http.sendRequest(request);
	
	std::cout << "REPONSE : " << response.getStatus();
	if (response.getStatus() == sf::Http::Response::Ok)
    {
        // affichage de la réponse du serveur
        std::cout << response.getBody() << std::endl;
    }
    else
    {
        std::cout << "request failed" << std::endl;
    }
	while(!quit)
	{

		if(levelState.getTurnToPlay() == state::PLAYER) {
			if (iaAutoMode) {
				//dumbAI.run(engine);
			}
		}
		else if (levelState.getTurnToPlay() == state::OPPONENT) {
		}

		engine.update();
	}
}

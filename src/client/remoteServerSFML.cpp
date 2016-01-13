#include "../common/server.hpp"
#include <iostream>
#include <SFML/Network.hpp>
#include <chrono>

using namespace server;

struct timer
{
    typedef std::chrono::steady_clock clock ;
    typedef std::chrono::seconds seconds ;

    void reset() { start = clock::now() ; }

    unsigned long long seconds_elapsed() const
    { return std::chrono::duration_cast<seconds>( clock::now() - start ).count() ; }

    private: clock::time_point start = clock::now() ;
};


RemoteServerSFML::RemoteServerSFML(){
}
RemoteServerSFML::~RemoteServerSFML(){
}
void RemoteServerSFML::run(){
	
	timer t ;
	

	
	while(!quit)
	{
		if (t.seconds_elapsed() > 1){		    
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
			if(levelState.getTurnToPlay() == state::PLAYER) {
				if (iaAutoMode) {
					//dumbAI.run(engine);
				}
			}
			else if (levelState.getTurnToPlay() == state::OPPONENT) {
			}
			engine.update();
			t.reset();
		}
	}
}

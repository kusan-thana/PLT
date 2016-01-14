#include "../common/server.hpp"
#include <iostream>
#include <SFML/Network.hpp>
#include <chrono>
#include "../common/engine.hpp"
using namespace server;

struct timer
{
    typedef std::chrono::steady_clock clock ;
    typedef std::chrono::milliseconds milliseconds ;

    void reset() { start = clock::now() ; }

    unsigned long long milliseconds_elapsed() const
    { return std::chrono::duration_cast<milliseconds>( clock::now() - start ).count() ; }

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
		if (t.milliseconds_elapsed() > 200){		    
			sf::Http::Request request("/command", sf::Http::Request::Get);
			sf::Http http("http://localhost/", 8080);
			sf::Http::Response response = http.sendRequest(request);
			
			std::cout << "REPONSE : " << response.getStatus();
			if (response.getStatus() == sf::Http::Response::Ok)
			{
				// affichage de la réponse du serveur
				//std::cout << response.getBody() << std::endl;
				
				Json::Reader jsonReader;
				Json::Value jsonIn;
				jsonReader.parse(response.getBody(),jsonIn);
					
				int type = jsonIn["type"].asInt();
				if(type == 1){
				//~ string file_name = jsonIn["file_name"].asString();
				//	engine.addCommand(std::move(make_unique<engine::LoadCommand>(file_name.c_str())));
				}
				else if (type == 2){
				//	int mode = jsonIn["mode"].asInt();
				//	engine.addCommand(std::move(make_unique<engine::ModeCommand>(static_cast<engine::EngineMode>(mode))));
				}
				else if (type == 3){
					int x = jsonIn["x"].asInt();
					int y = jsonIn["y"].asInt();
					state::Element* character = (state::Element*) (intptr_t) jsonIn["character"].asInt();
					engine::MoveCommand* move = new engine::MoveCommand(x, y, character);
					engine.addCommand(move);
				}
				else if (type == 4){
					//~ state::Element* attacker = in["attacker"].asInt();
					//~ string target = in["target"].asString();
					//state::Element* attacker = (state::Element*) (intptr_t) jsonIn["attacker"].asInt();
					//state::Element* target = (state::Element*) (intptr_t) jsonIn["target"].asInt();
					//engine.addCommand(std::move(make_unique<engine::AttackCommand>(attacker,target)));
				}
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
void RemoteServerSFML::addCommand(engine::Command *cmd) {
	sf::Http::Request request("/command/1", sf::Http::Request::Post);
    
    Json::Value json;
		
	json["type"] = cmd->getTypeId();
    if (cmd->getTypeId() == 1){
		json["file_name"] = ((engine::LoadCommand*)cmd)->getFileName();
	}
	else if(cmd->getTypeId() == 2){
		json["mode"] = ((engine::ModeCommand*)cmd)->getMode();
	}
	else if(cmd->getTypeId() == 3){
		json["x"] = ((engine::MoveCommand*)cmd)->getPositionX();
		json["y"] = ((engine::MoveCommand*)cmd)->getPositionY();
		json["character"] = (int)(intptr_t)((engine::MoveCommand*)cmd)->getCharacter();
		//std::cout << "CHARACTER" << ((engine::MoveCommand*)cmd)->getCharacter(); 		
	}
	else if(cmd->getTypeId() == 4){
		json["attacker"] = ((engine::AttackCommand*)cmd)->getAttacker();
		json["target"] = ((engine::AttackCommand*)cmd)->getTarget();
	}
  
    request.setBody(json.toStyledString());
    
    std::cout << json.toStyledString();
	sf::Http http("http://localhost", 8080);
	
	sf::Http::Response response = http.sendRequest(request);
	
	std::cout << "REPONSE : " << response.getStatus();
	if (response.getStatus() == sf::Http::Response::NoContent)
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

}

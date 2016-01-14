#include "../common/server.hpp"
#include <iostream>
using namespace server;

CommandService::CommandService (CommandDB& commandDB) : AbstractService("/command"), commandDB(commandDB) {
    
}
HttpStatus CommandService::get (Json::Value& out, int id) const {
    const engine::Command* command = commandDB.getCommand();
    if (!command)
        throw ServiceException(HttpStatus::NOT_FOUND,"No command");
    
    out["type"] = command->getTypeId();
    
    switch(command->getTypeId()){
		case engine::CommandTypeId::MAIN :
			out["file_name"] = ((engine::LoadCommand*)command)->getFileName();
		break;
		case engine::CommandTypeId::MODE :
			out["mode"] = ((engine::ModeCommand*)command)->getMode();
		break;
		case engine::CommandTypeId::MOVE :
			out["x"] = ((engine::MoveCommand*)command)->getPositionX();
			out["y"] = ((engine::MoveCommand*)command)->getPositionY();
			out["character"] = (int)(intptr_t)((engine::MoveCommand*)command)->getCharacter();
		break;
		case engine::CommandTypeId::ATTACK :
			out["attacker"] = (int)(intptr_t)((engine::AttackCommand*)command)->getAttacker();
			out["target"] = (int)(intptr_t)((engine::AttackCommand*)command)->getTarget();
		break;
	}
	commandDB.removeCommand();
    return HttpStatus::OK;
}

HttpStatus CommandService::put (Json::Value& out,const Json::Value& in) {
    //~ string name = in["name"].asString();
    //~ int age = in["age"].asInt();
    //~ out["id"] = userDB.addUser(make_unique<User>(name,age));
    
    int type = in["type"].asInt();
    
    if(type == 1){
		string file_name = in["file_name"].asString();
		commandDB.setCommand(std::move(make_unique<engine::LoadCommand>(file_name.c_str())));
	}
	else if (type == 2){
		int mode = in["mode"].asInt();
		commandDB.setCommand(std::move(make_unique<engine::ModeCommand>(static_cast<engine::EngineMode>(mode))));
	}
	else if (type == 3){
		int x = in["x"].asInt();
		int y = in["y"].asInt();
		state::Element* character = (state::Element*) (intptr_t) in["character"].asInt();
		commandDB.setCommand(std::move(make_unique<engine::MoveCommand>(x,y,character)));
	}
	else if (type == 4){
		//~ state::Element* attacker = in["attacker"].asInt();
		//~ string target = in["target"].asString();
		state::Element* attacker = (state::Element*) (intptr_t) in["attacker"].asInt();
		state::Element* target = (state::Element*) (intptr_t) in["target"].asInt();
		commandDB.setCommand(std::move(make_unique<engine::AttackCommand>(attacker,target)));
	}

    return HttpStatus::CREATED;
}
HttpStatus CommandService::post (const Json::Value& in, int id) {
	
    if(in.isMember("type")){
		int type = in["type"].asInt();
		
		if(type == 1){
			string file_name = in["file_name"].asString();
			commandDB.setCommand(std::move(make_unique<engine::LoadCommand>(file_name.c_str())));
		}
		else if (type == 2){
			int mode = in["mode"].asInt();
			commandDB.setCommand(std::move(make_unique<engine::ModeCommand>(static_cast<engine::EngineMode>(mode))));
		}
		else if (type == 3){
			int x = in["x"].asInt();
			int y = in["y"].asInt();
			std::cout << "CHARACTER" << (state::Element*) (intptr_t) in["character"].asInt(); 		

			state::Element* character = (state::Element*) (intptr_t) in["character"].asInt();
			commandDB.setCommand(std::move(make_unique<engine::MoveCommand>(x,y,character)));
		}
		else if (type == 4){
			//~ state::Element* attacker = in["attacker"].asInt();
			//~ string target = in["target"].asString();
			state::Element* attacker = (state::Element*) (intptr_t) in["attacker"].asInt();
			state::Element* target = (state::Element*) (intptr_t) in["target"].asInt();
			commandDB.setCommand(std::move(make_unique<engine::AttackCommand>(attacker,target)));
		}
	}
	return HttpStatus::NO_CONTENT;
	
}
//~ HttpStatus UserService::remove (int id) {
    //~ const User* user = userDB.getUser(id);
    //~ if (!user)
        //~ throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    //~ userDB.removeUser(id);
    //~ return HttpStatus::NO_CONTENT;
//~ }


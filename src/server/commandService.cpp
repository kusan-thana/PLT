#include "../common/server.hpp"

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
		break;
		case engine::CommandTypeId::ATTACK :
			out["attacker"] = ((engine::AttackCommand*)command)->getAttacker();
			out["target"] = ((engine::AttackCommand*)command)->getTarget();
		break;
	}
  
    return HttpStatus::OK;
}

HttpStatus CommandService::put (Json::Value& out,const Json::Value& in) {
    //~ string name = in["name"].asString();
    //~ int age = in["age"].asInt();
    //~ out["id"] = userDB.addUser(make_unique<User>(name,age));
    return HttpStatus::CREATED;
}

//~ HttpStatus UserService::remove (int id) {
    //~ const User* user = userDB.getUser(id);
    //~ if (!user)
        //~ throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
    //~ userDB.removeUser(id);
    //~ return HttpStatus::NO_CONTENT;
//~ }


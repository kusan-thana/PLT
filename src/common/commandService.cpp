#include "server.hpp"

using namespace server;

CommandService::CommandService (CommandDB& commandDB) : AbstractService("/command"), commandDB(commandDB) {
    
}
HttpStatus CommandService::get (Json::Value& out, int id) const {
    const engine::Command* command = commandDB.getCommand();
    if (!command)
        throw ServiceException(HttpStatus::NOT_FOUND,"No command");
    
    out["name"] = "Kusan";
    
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


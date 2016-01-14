#include "../common/server.hpp"
#include <iostream>

using namespace server;

CommandDB::CommandDB() {
    
}

const engine::Command* CommandDB::getCommand () const {
    //~ auto ite = users.find(id);
    //~ if (ite == users.cend())
        //~ return nullptr;
    //~ return ite->second.get();
    return command.get();
}
void CommandDB::setCommand (unique_ptr<engine::Command> command) {
    //~ users[id] = std::move(user);
    //~ if (id > idseq) {
        //~ idseq = id;
    //~ }
    this->command = std::move(command);
}

void CommandDB::removeCommand () {
    //~ auto ite = users.find(id);
    //~ if (ite == users.end())
        //~ return;
    //~ users.erase(ite);
    command = NULL;
}



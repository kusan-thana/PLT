#include "engine.hpp"

using namespace engine;


LoadCommand::LoadCommand(const char* f):file_name(f)
{
}


LoadCommand::~LoadCommand()
{
}

CommandTypeId LoadCommand::getTypeId() const{
	return MAIN;
}

const char * engine::LoadCommand::getFileName() const
{
	return file_name.data();
}	

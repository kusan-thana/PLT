#include "loadCommand.hpp"

using namespace engine;


LoadCommand::LoadCommand(const char* f):fileName(f)
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
	return fileName.data();
}	

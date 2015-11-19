#pragma once
#include "command.hpp"
#include <string>
namespace engine{
	class LoadCommand : public Command
	{
	protected:
		std::string fileName;

	public:
		LoadCommand(const char* f);
		~LoadCommand();
		CommandTypeId getTypeId() const;
		const char* getFileName() const;
	};
}

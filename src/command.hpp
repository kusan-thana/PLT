#ifndef Command_H
#define Command_H

namespace engine {
	enum CommandTypeId { MAIN = 1, MODE = 2, SELECTION = 3, ACTIVATE = 4};


	class Command {
	public:
		virtual ~Command();
		virtual CommandTypeId Command::getCommandTypeId() const = 0;
	};
}
#endif

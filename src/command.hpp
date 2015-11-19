#ifndef Command_H
#define Command_H

namespace engine {
	enum CommandTypeId { MAIN = 1, MODE = 2, MOVE = 3};

	class Command {
	public:
		virtual ~Command() {};
		virtual CommandTypeId getTypeId() const = 0;
	};
}
#endif

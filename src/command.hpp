#ifndef Command_H
#define Command_H

namespace engine {
	enum CommandTypeId { MAIN = 1, MODE = 2, SELECTION = 3, ACTIF = 4};


	class Command {
	protected:
		Command();	//Un constructeur pour une classe abstraite ?!
		//Mais encore...
	};
}
#endif

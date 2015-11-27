#pragma once
#include "command.hpp"
#include "levelState.hpp"

namespace engine {
	class AttackCommand : public Command{
	protected:
		state::Element *attacker, *target;

	public:

		AttackCommand(state::Element* attacker, state::Element* target);
		~AttackCommand();
		state::Element* getAttacker();
		state::Element* getTarget();
		virtual CommandTypeId getTypeId() const;

};
}

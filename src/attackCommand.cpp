#include "attackCommand.hpp"

using namespace::engine;

AttackCommand::AttackCommand()
{
}


engine::AttackCommand::AttackCommand(state::Element* attacker, state::Element* target) : attacker(attacker), target(target)
{
}

AttackCommand::~AttackCommand()
{
}

state::Element * engine::AttackCommand::getAttacker()
{
	return attacker;
}

state::Element * engine::AttackCommand::getTarget()
{
	return target;
}

void engine::AttackCommand::apply(state::LevelState &)
{
}

#include "attackCommand.hpp"
#include <iostream>

using namespace::engine;


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


CommandTypeId engine::AttackCommand::getTypeId() const
{
	return ATTACK;
}

#include "activerPersonnage.hpp"

#include <iostream>
using namespace engine;

ActiverPersonnage::ActiverPersonnage(state::Element* perso) : perso(perso)
{
}


ActiverPersonnage::~ActiverPersonnage()
{
}


void ActiverPersonnage::apply(state::LevelState& levelState) {

	perso->setActive(!perso->isActive());
	std::cout << perso->isActive();
}



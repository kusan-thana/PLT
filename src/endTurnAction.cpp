#include "endTurnAction.hpp"
#include "mobileElement.hpp"

using namespace engine;

EndTurnAction::EndTurnAction(state::Element* character) : character(character)
{
}


EndTurnAction::~EndTurnAction()
{
}

void EndTurnAction::apply(state::LevelState& levelState) {
	((state::MobileElement*)character)->setTurnPlayed(true);
	levelState.getElementList().notifyObservers(-1);
}


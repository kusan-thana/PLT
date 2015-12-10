#include "engine.hpp"

using namespace engine;

EndTurnAction::EndTurnAction(state::Element* character) : character(character)
{
}


EndTurnAction::~EndTurnAction()
{
}

void EndTurnAction::apply(state::LevelState& levelState) {
	((state::MobileElement*)character)->setTurnPlayed(true);
	levelState.getElementList().notifyObservers(levelState.getElementList().getIdxElement(character));
}

void EndTurnAction::undo(state::LevelState& levelState) {
}

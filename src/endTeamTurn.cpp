#include "engine.hpp"

using namespace engine;

EndTeamTurn::EndTeamTurn(state::TurnToPlay team) : team(team)
{
}


EndTeamTurn::~EndTeamTurn()
{
}

void EndTeamTurn::apply(state::LevelState& levelState){
	state::ElementList& elementList = levelState.getElementList();
	levelState.setTurnToPlay(state::OPPONENT); //Opponent turn
	for (int j = 0, count = 0; j < elementList.size(); j++) {
		state::MobileElement* curr_mobileElement = (state::MobileElement*)elementList.getElement(j);
		if (curr_mobileElement->isPlayerCharacter()) {
			((state::MobileElement*)(elementList.getElement(j)))->setTurnPlayed(false); //Reinitialization - ce element peut jouer a nouveau
			((state::MobileElement*)(elementList.getElement(j)))->setMovePlayed(false); //Reinitialization - ce element peut jouer a nouveau
			levelState.getElementList().notifyObservers(j);
		}
	}
}

void EndTeamTurn::undo(state::LevelState& levelState) {


}

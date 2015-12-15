#include "engine.hpp"

using namespace engine;

EndTeamTurn::EndTeamTurn(state::TurnToPlay team) : team(team)
{
}


EndTeamTurn::~EndTeamTurn()
{
}

void EndTeamTurn::apply(state::LevelState& levelState){


}

void EndTeamTurn::undo(state::LevelState& levelState) {


}

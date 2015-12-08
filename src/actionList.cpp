#include "actionList.hpp"
#include <iostream>
using namespace engine;

ActionList::ActionList(state::LevelState& levelState) : levelState(levelState){
}
int ActionList::size() const{

	return this->actions.size();
}
Action* ActionList::get(int i) const{

	return actions[i];
}
void ActionList::apply(){
		
	for(int i=0; i<size(); i++){

		actions[i]->apply(levelState);
	}
}
void ActionList::add(Action* action){

	actions.push_back(action);
}

void ActionList::clear() {
	actions.clear();
}

#ifndef SearchTree_H
#define SearchTree_H
#include "levelState.hpp"
#include "searchNode.hpp"

namespace ai {
	
class SearchTree  {
	
	protected:
		state::LevelState& levelState;
		SearchNode* root;
		
		void generateNodes(SearchNode* root, std::vector<SearchNode*>& list);

	public:
		SearchTree(state::LevelState& levelState);
};
}
#endif

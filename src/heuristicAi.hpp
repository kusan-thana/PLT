#ifndef HeuristicAI_H
#define HeuristicAI_H
#include "dumbAi.hpp"
#include "pathMap.hpp"
#include "commandSet.hpp"

namespace ai {
	
class HeuristicAI : public DumbAI{

	protected:
		PathMap playerCharsMap;
		PathMap monstersMap;
		bool moveToClosest(engine::CommandSet& commands,const PathMap& path);
		
	public:
		HeuristicAI(state::LevelState& mainLevelState);
		void run(engine::CommandSet& commands);

};
}
#endif

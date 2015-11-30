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
		bool moveToClosest(engine::Engine& engine,const PathMap& path, state::Element* element);
		
	public:
		HeuristicAI(state::LevelState& mainLevelState);
		void run(engine::Engine& engine, state::Element* element);

};
}
#endif

#ifndef HeuristicAI_H
#define HeuristicAI_H
#include "dumbAi.hpp"
#include "pathMap.hpp"
#include "commandSet.hpp"

namespace ai {
	
class HeuristicAI : public DumbAI{

	protected:
		PathMap hero;
		PathMap minions;
		bool moveToClosest(engine::CommandSet& commands,const PathMap& path);
		
	public:

};
}
#endif

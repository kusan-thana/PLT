#pragma once
#include "commandSet.hpp"
#include "levelState.hpp"
namespace engine {
	enum EngineMode { PLAY = 1, RECORD = 2};

	class Engine {
		
	protected:
		CommandSet commandSet;
		state::LevelState& levelState;
		
	public:
		Engine(state::LevelState& levelState);
		~Engine();
		void addCommand(engine::Command *cmd);
		void update();
	};
}

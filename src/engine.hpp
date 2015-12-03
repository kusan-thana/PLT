#pragma once
#include "commandSet.hpp"
#include "levelState.hpp"
#include "actionList.hpp"

namespace engine {
	enum EngineMode { PLAY = 0, RECORD = 1, REPLAY = 2};

	class Engine {
		
	protected:
		CommandSet commandSet;
		state::LevelState& levelState;
		EngineMode enginemode;
		ActionList actions;

		void setMode(EngineMode mode);
	public:
		Engine(state::LevelState& levelState);
		~Engine();
		void addCommand(engine::Command *cmd);
		void update();
		void turnGestion();
		EngineMode getMode();

	};
}

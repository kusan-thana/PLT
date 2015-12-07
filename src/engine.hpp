#pragma once
#include "commandSet.hpp"
#include "levelState.hpp"
#include "actionList.hpp"

namespace engine {
	enum EngineMode { PLAY = 0, SAVE = 1, LOADSAVE = 2, ROLLBACK = 3};

	class Engine {
		
	protected:
		CommandSet commandSet;
		state::LevelState& levelState;
		EngineMode engineMode;
		ActionList actions;
		state::LevelState* levelStateSave;

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

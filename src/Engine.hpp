#pragma once
#include "CommandSet.hpp"
#include "levelState.hpp"
namespace engine {
	class Engine {
	protected:
		CommandSet commandSet;
		state::LevelState levelState;
	public:
		Engine();
		~Engine();
		void Engine::addCommand(engine::Command *cmd);
		void Engine::update();
	};
}

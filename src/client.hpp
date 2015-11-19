#ifndef Client_H
#define Client_H
#include "tileSet.hpp"
#include "scene.hpp"
#include "engine.hpp"
#include "gui.hpp"
#include "dumbAi.hpp"

namespace client {

class Client {
	
	protected:
		state::LevelState levelState; 
		std::vector<const render::TileSet*> tileSets;
		render::Scene scene;
		engine::Engine engine; //A déplacer apres la modularisation 
		gui::GUI gui;
		ai::DumbAI dumbAI;

		Client();
		void setTileSet(render::SceneLayer sceneLayer, const render::TileSet* tileSet);
		virtual void init();
		virtual bool acquireControls() = 0;
		//virtual void stateChanged() = 0;
		virtual void updateDisplay() = 0;
		
	public:
		void run();

};
}
#endif

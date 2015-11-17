#ifndef Client_H
#define Client_H
#include "tileSet.hpp"
#include "scene.hpp"
#include "engine.hpp"
#include "GUI.hpp"

namespace client {

class Client {
	
	protected:
		std::vector<const render::TileSet*> tileSets;
		render::Scene scene;
		engine::Engine engine; //A d�placer apres la modularisation 
		gui::GUI gui;

		Client();
		void setTileSet(render::SceneLayer sceneLayer, const render::TileSet* tileSet);
		virtual void init();
		virtual bool acquireControls() = 0;
		//virtual void stateChanged() = 0;
		virtual void updateDisplay() = 0;
		
	public:
		state::LevelState levelState; 
		void run();

};
}
#endif

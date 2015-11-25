#ifndef GUI_H
#define GUI_H

#include "guiObservable.hpp"
#include "levelState.hpp"
#include "guiElementList.hpp"
#include "guiMoveRange.hpp"
#include "engine.hpp"

namespace gui
{ 
	class GUI : public GUIObservable
	{
	protected:
		state::LevelState& levelState;
		engine::Engine& engine;
		GUIElementList cursorList;
		GUIMoveRange moveRange;
		engine::EngineMode engineMode;
		GUIElementList healthBarList;
		
	public:
		GUI(state::LevelState& levelState, engine::Engine&);
		~GUI();
		GUIElementList& getCursorList();
		GUIMoveRange& getMoveRange();
		GUIElementList& getHealthBarList();
		state::LevelState& getLevelState();
		void setCursorList(const GUIElementList& cursor);
		void commander(engine::Engine& engine); //Creer les commandes pour le moteur de jeu par rapport a l'etat gui
		void setEngineMode(engine::EngineMode engineMode);
		void init();
		void updateHealthBarList();
	};
}
#endif

#ifndef GUI_H
#define GUI_H

#include "guiObservable.hpp"
#include "levelState.hpp"
#include "cursor.hpp"
#include "engine.hpp"

namespace gui
{ 
	class GUI : public GUIObservable
	{
	protected:
		state::LevelState& levelState;
		Cursor cursor;
		 engine::EngineMode engineMode;
		
	public:
		GUI(state::LevelState& levelState);
		~GUI();
		Cursor& getCursor();
		void setCursor(const Cursor& cursor);
		void commander(engine::Engine& engine); //Creer les commandes pour le moteur de jeu par rapport a l'etat gui
		void setEngineMode(engine::EngineMode engineMode);
	};
}
#endif

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
		engine::Engine& engine;
		Cursor cursor;
		
	public:
		GUI(state::LevelState& levelState, engine::Engine&);
		~GUI();
		Cursor& getCursor();
		void setCursor(const Cursor& cursor);
		void commander(); //Creer les commandes pour le moteur de jeu par rapport a l'etat gui


	};
}
#endif

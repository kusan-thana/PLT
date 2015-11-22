#ifndef GUILayer_H
#define GUILayer_H
#include "guiObserver.hpp"
#include "surface.hpp"
#include "tileSet.hpp"
#include "guiEvent.hpp"
#include "guiElementList.hpp"

namespace guiRender {
	
class GUILayer : public gui::GUIObserver{
	
	protected:
		Surface* surface;
		const render::TileSet* tileSet;
		
	public:
		GUILayer();
		virtual ~GUILayer();
		const render::TileSet* getTileSet() const;
		void setTileSet(const render::TileSet* tileSet);
		void setSurface(Surface* surface);
		virtual void guiChanged(const gui::GUIEvent& e);
		void update(gui::GUIElementList& guiElementList, int i);
};
}
#endif

#include "gui_state.h"
#include "render.h"

namespace guiRender {

  /// class GUILayer - 
  class GUILayer : public GUIObserver {
    // Associations
    render::TileSet* unnamed;
    render::Surface* unnamed;
    // Attributes
  protected:
    render::Surface* surface;
    const render::TileSet* tileSet;
    // Operations
  public:
    GUILayer ();
    ~GUILayer ();
    const TileSet* const getTileSet ();
    void setTileSet (const TileSet* tileSet);
    void setSurface (Surface* surface);
    void guiChanged (const gui::GUIEvent& e);
    void update (gui::GUIElementList& guiElementList, int i);
  };

};


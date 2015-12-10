#ifndef GUIRENDER__H
#define GUIRENDER__H

#include "gui.h"

namespace guiRender {

  /// class GUILayer - 
  class GUILayer : public gui::GUIObserver {
    // Associations
    // Attributes
  protected:
    render::Surface* surface;
    const render::TileSet* tileSet;
    // Operations
  public:
    GUILayer ();
    virtual ~GUILayer ();
    const render::TileSet* getTileSet () const;
    void setTileSet (const render::TileSet* tileSet);
    void setSurface (render::Surface* surface);
    void guiChanged (const gui::GUIEvent& e);
    void update (gui::GUIElementList& guiElementList, int i);
  };

  /// class TileSet3 - 
  class TileSet3 : public render::TileSet {
    // Attributes
  protected:
    std::vector<render::Tile*> tiles;
    const char* file_name;
    int widthCell;
    int heightCell;
    // Operations
  public:
    TileSet3 ();
    int getCellWidth () const;
    int getCellHeight () const;
    const char* getImageFile () const;
    const render::Tile* getElementTile (const state::Element* element) const;
    const render::Tile* getElementTile (gui::Cursor& cursor) const;
  };

  enum TileID3 {
    RED     = 0,
    YELLOW     = 1,
    GREEN     = 2,
    HEALTH_BAR_RED     = 3,
    HEALTH_BAR_GREEN     = 4
  };

};

#endif

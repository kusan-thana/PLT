#ifndef RENDER__H
#define RENDER__H

namespace render {

  /// class TileSet - 
  class TileSet {
    // Operations
  public:
    virtual ~TileSet ();
    virtual int const getCellWidth () = 0;
    virtual int const getCellHeight () = 0;
    virtual const char* const getImageFile () = 0;
    virtual const render::Tile* const getCursorTile () = 0;
  };

  /// class Surface - 
  class Surface {
    // Operations
  public:
    virtual ~Surface ();
    virtual void clear () = 0;
    virtual void loadTexture (const char* image_file) = 0;
    virtual void setSpriteCount (int n) = 0;
    virtual void setSpriteLocation (int i, int x, int y) = 0;
    virtual void setSpriteTexture (int i, const render::StaticTile* staticTile) = 0;
  };

};

#endif

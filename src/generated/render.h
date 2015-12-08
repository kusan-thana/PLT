#ifndef RENDER__H
#define RENDER__H

namespace render {

  /// class TileSet - 
  class TileSet {
    // Operations
  public:
    virtual ~TileSet ();
    virtual int getCellWidth () const = 0;
    virtual int getCellHeight () const = 0;
    virtual const char* getImageFile () const = 0;
    virtual const render::Tile* getCursorTile () const = 0;
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

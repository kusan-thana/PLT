#ifndef RENDER__H
#define RENDER__H

#include "state.h"

namespace render {

  /// class Tile - 
  class Tile {
    // Operations
  public:
    virtual ~Tile ();
    virtual bool const isAnimated ();
  };

  /// class TileSet - Stocke un ensemble de tuiles et animations possibles pour plan donnée
  class TileSet {
    // Associations
    // Operations
  public:
    virtual ~TileSet ();
    virtual int const getCellWidth () = 0;
    virtual int const getCellWidth () = 0;
    virtual const char* const getImageFile () = 0;
    virtual const Tile* const getElementTile (const Element* element) = 0;
  };

  /// class Animation - 
  class Animation {
    // Associations
    // Attributes
  public:
    int i;
  protected:
    int x;
    int y;
    const Tile* tile;
    // Operations
  public:
    void Animation (int i, int x, int y, Tile* tile);
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
    virtual void setSpriteTexture (int i, const StaticTile* staticTile) = 0;
  };

  /// class Layer - 
  class Layer {
    // Associations
    // Attributes
  protected:
    Surface* surface;
    const TileSet* tileSet;
    std::map<int,Animation*> animations;
    // Operations
  public:
    Layer ();
    virtual ~Layer ();
    const TileSet* const getTileSet ();
    void setTileSet (const TileSet* tileSet);
    void setSurface (Surface* surface);
  };

  enum SceneLayer {
    GRID_LAYER,
    CURSORS_LAYER,
    CHARACTERS_LAYER,
    STATE_LAYER
  };

  /// class ElementListLayer - 
  class ElementListLayer : public render::Layer {
    // Operations
  public:
    void levelStateChanged (const state::LevelStateEvent& e);
  };

  /// class Scene - 
  class Scene : public state::LevelStateObserver {
    // Associations
    // Attributes
  public:
    int width;
    int height;
    std::vector<Layer*> layers;
    // Operations
  public:
    Scene ();
    ~Scene ();
    void setLayer (int idx, Layer* layer);
    void levelStateChanged (const state::LevelStateChanged& e);
  };

  /// class StaticTile - 
  class StaticTile : public render::Tile {
    // Attributes
  protected:
    int x;
    int y;
    int width;
    int height;
    // Operations
  public:
    StaticTile (int x, int y, int width, int heigth);
    bool const isAnimated ();
    int const getX ();
    int const getY ();
    int const getWidth ();
    int const getHeight ();
    void setX (int x);
    void setY (int y);
    void setWidth (int width);
    void setHeight (int height);
  };

  /// class AnimatedTile - 
  class AnimatedTile : public render::Tile {
    // Associations
    // Attributes
  public:
    std::vector<const Tile*> tiles;
    float rate;
    // Operations
  public:
    bool const isAnimated ();
    float const getRate ();
    const Tile* const getTile (int i);
    void addTile (Tile* tle);
    void setRate (float rate);
  };

};

#endif

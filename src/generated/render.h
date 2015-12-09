#ifndef RENDER__H
#define RENDER__H

#include "state.h"

namespace render {

  /// class Tile - 
  class Tile {
    // Operations
  public:
    virtual ~Tile ();
    virtual bool isAnimated () const = 0;
  };

  /// class TileSet - Stocke un ensemble de tuiles et animations possibles pour plan donnée
  class TileSet {
    // Associations
    // Operations
  public:
    virtual ~TileSet ();
    virtual int getCellWidth () const = 0;
    virtual int getCellWidth () const = 0;
    virtual const char* getImageFile () const = 0;
    virtual const Tile* getElementTile (const Element* element) const = 0;
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
    Surface* getSurface ();
  };

  /// class Layer - 
  class Layer : public state::LevelStateObserver {
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
    const TileSet* getTileSet () const;
    void setTileSet (const TileSet* tileSet);
    void setSurface (Surface* surface);
    Surface* getSurface () const;
  };

  enum SceneLayer {
    GRID_LAYER     = 0,
    MOVE_RANGE     = 1,
    CURSORS_LAYER     = 2,
    TILE_LIST_LAYER     = 3,
    CHARACTERS_LAYER     = 4
  };

  /// class ElementListLayer - 
  class ElementListLayer : public render::Layer {
    // Operations
  public:
    void levelStateChanged (const state::LevelStateEvent& e);
  protected:
    void update (const state::ElementList& elementList, int i);
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
    void levelStateChanged (const state::LevelStateEvent& e);
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
    StaticTile (int x, int y, int width, int height);
    bool isAnimated () const;
    int getX () const;
    int getY () const;
    int getWidth () const;
    int getHeight () const;
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
    bool isAnimated () const;
    float getRate () const;
    const Tile* getTile (int i) const;
    void addTile (Tile* tle);
    void setRate (float rate);
  };

  /// class SFMLSurface - 
  class SFMLSurface : public render::Surface {
    // Attributes
  protected:
    sf::VertexArray vertices;
    sf::Texture tileSet;
    int widthSprite;
    int heigthSprite;
    // Operations
  public:
    void clear ();
    void loadTexture (const char* tileset);
    void setSpriteCount (int n);
    void setSpriteLocation (int i, int x, int y);
    void setSpriteTexture (int i, const StaticTile* staticTile);
    void setSpriteWidth (int widthSprite, int heightSprite);
    SFMLSurface& getSfmlSurface ();
  private:
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;
  };

};

#endif

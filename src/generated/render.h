#ifndef RENDER__H
#define RENDER__H


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
    virtual int getCellHeight () const = 0;
    virtual const char* getImageFile () const = 0;
    virtual const render::Tile* getElementTile (const state::Element* element) const = 0;
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
    Animation (int i, int x, int y, Tile* tile);
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
  class Layer : public state::LevelStateObserver {
    // Associations
    // Attributes
  protected:
    Surface* surface;
    const TileSet* tileSet;
    std::unordered_map<int,Animation*> animations;
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
    MOVE_RANGE_LAYER     = 1,
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
    void addTile (Tile* tile);
    void setRate (float rate);
  };

  /// class SFMLSurface - 
  class SFMLSurface : public render::Surface {
    // Attributes
  protected:
    sf::VertexArray vertices;
    sf::Texture tileset;
    int widthSprite;
    int heightSprite;
    // Operations
  public:
    void clear ();
    void loadTexture (const char* tileset);
    void setSpriteCount (int n);
    void setSpriteLocation (int i, int x, int y);
    void setSpriteTexture (int i, const StaticTile* staticTile);
    void setSpriteWidth (int spriteWidth);
    void setSpriteHeight (int spriteHeight);
    SFMLSurface& getSfmlSurface ();
  private:
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;
  };

  enum TileID1 {
    TREE     = 0,
    WATER     = 1,
    GRASS     = 2,
    FIR     = 3
  };

  /// class TileSet1 - 
  class TileSet1 : public render::TileSet {
    // Associations
    // Attributes
  protected:
    std::vector<Tile*> tiles;
    const char* file_name;
    int widthCell;
    int heightCell;
    // Operations
  public:
    TileSet1 ();
    int getCellWidth () const;
    int getCellHeight () const;
    const char* getImageFile () const;
    const Tile* getElementTile (const state::Element* element) const;
  };

  enum TileID2 {
    HERO     = 0,
    WIZARD     = 1,
    MINION     = 2,
    INACTIVE_HERO     = 3,
    INACTIVE_WIZARD     = 4,
    INACTIVE_MINION     = 5
  };

  /// class TileSet2 - 
  class TileSet2 : public render::TileSet {
    // Associations
    // Attributes
  protected:
    std::vector<Tile*> tiles;
    const char* file_name;
    int widthCell;
    int heightCell;
    // Operations
  public:
    TileSet2 ();
    int getCellWidth () const;
    int getCellHeight () const;
    const char* getImageFile () const;
    const Tile* getElementTile (const state::Element* element) const;
  };

};

#endif

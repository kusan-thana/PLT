#ifndef AI__H
#define AI__H


namespace ai {

  /// class AI - 
  class AI {
    // Attributes
  protected:
    const state::LevelState& mainLevelState;
    // Operations
  public:
    AI (const state::LevelState& mainLevelState);
    virtual ~AI ();
    virtual void run (engine::Engine& engine) = 0;
  };

  /// class DumbAI - 
  class DumbAI : public ai::AI {
    // Operations
  public:
    DumbAI (state::LevelState& mainLevelState);
    void run (engine::Engine& engine);
  protected:
    void dumbMove (int idx, engine::CommandSet& command);
  };

  /// class Coords - 
  class Coords {
    // Attributes
  public:
    int x;
    int y;
    int value;
    // Operations
  public:
    Coords (int x, int y);
    Coords (int x, int y, state::Direction direction);
    Coords (int x, int y, state::Direction direction, int value);
    bool operator< (const Coords&  coords) const;
  };

  /// class PathMap - 
  class PathMap {
    // Attributes
  protected:
    const state::LevelState& levelState;
    int* weights;
    int width;
    int height;
    std::vector<state::Element*> elements;
    // Operations
  public:
    PathMap (state::LevelState& levelState);
    ~PathMap ();
    void clear ();
    void addElement (state::Element* element);
    int getWidth () const;
    int getHeight () const;
    int* getWeights () const;
    int getMetadata (int x, int y) const;
    int getMetadata (int x, int y, state::Direction direction) const;
    void setMetadata (int x, int y, int value);
    void setMetadata (int x, int y, int value, state::Direction direction);
    void initMetadata (int defaultValue);
    bool isValid (int x, int y) const;
    bool isValid (int x, int y, state::Direction direction) const;
    int relax (int x, int y, state::Direction direction);
    void dijsktra ();
    void display ();
  };

  /// class HeuristicAI - 
  class HeuristicAI : public ai::DumbAI {
    // Operations
  public:
    HeuristicAI (state::LevelState& mainLevelState);
    void run (engine::Engine& engine);
  protected:
    bool moveToClosest (engine::Engine& engine, const PathMap& path, state::Element* element);
    bool attackToClosest (engine::Engine& engine, const PathMap& path, state::Element* element);
  };

};

#endif

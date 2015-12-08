
namespace ai {

  /// class AI - 
  class AI {
    // Attributes
  protected:
    const state::LevelState& mainLevelState;
    // Operations
  public:
    AI (const state::LevelState& mainLevelState);
    virtual ~AI () = 0;
    virtual void run (engine::Engine& engine) = 0;
  };

  /// class DumbAI - 
  class DumbAI : public AI {
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
    bool const operator< (const Coords&  coords);
  };

  /// class PathMap - 
  class PathMap {
    // Attributes
  public:
    state::LevelState& levelState;
    int* weights;
    int width;
    int height;
    std::vector<Element*> elements;
    // Operations
  public:
    PathMap (state::LevelState& levelState);
    ~PathMap ();
    void clear ();
    void addElement (state::Element* element);
    int const getWidth ();
    int const getHeight ();
    int* const getWeights ();
    int const getMetadata (int x, int y);
    int const getMetadata (int x, int y, state::Direction direction);
    void setMetadata (int x, int y, int value);
    void setMetadata (int x, int y, int value, state::Direction direction);
    void initMetadata (int defaultValue);
    bool const isValid (int x, int y, state::Direction direction);
    int relax (int x, int y, state::Direction direction);
    void dijsktra ();
  };

  /// class HeuristicAI - 
  class HeuristicAI : public DumbAI {
    // Operations
  public:
    HeuristicAI (state::LevelState& mainLevelState);
    void run (engine::Engine& engine);
  protected:
    bool moveToClosest (engine::Engine& engine, const PathMap& path, state::Element* element);
    bool attackToClosest (engine::Engine& engine, const PathMap& path, state::Element* element);
  };

};


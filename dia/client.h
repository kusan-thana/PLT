
namespace client {

  /// class Client - 
  class Client {
    // Attributes
  protected:
    std::vector<const render::TileSet*> tileSets;
    render::Scene scene;
    engine::Engine engine;
    gui::GUI gui;
    ai::DumbAI dumbAI;
    ai::HeuristicAI heuristicAi;
    // Operations
  public:
    Client ();
    void run ();
  protected:
    void setTileSet (render::SceneLayer sceneLayer, const render::TileSet* tileSet);
    void init ();
    virtual bool acquireControls () = 0;
    virtual void stateChanged () = 0;
    virtual void updateDisplay () = 0;
  };

  /// class SFMLClient - 
  class SFMLClient : public Client {
    // Attributes
  protected:
    sf::RenderWindow window;
    std::vector<Surface*> surfaces;
    // Operations
  public:
    SFMLClient ();
  protected:
    void init ();
    bool acquireControls ();
    void stateChanged ();
    void updateChanged ();
  };

};


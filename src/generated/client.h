#ifndef CLIENT__H
#define CLIENT__H


namespace client {

  /// class Client - 
  class Client {
    // Attributes
  protected:
    state::LevelState levelState;
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
    virtual void init ();
    virtual bool acquireControls () = 0;
    virtual void updateDisplay () = 0;
  };

  /// class SFMLClient - 
  class SFMLClient : public client::Client {
    // Attributes
  protected:
    sf::RenderWindow window;
    std::vector<render::Surface*> surfaces;
    sf::Text text;
    sf::Font font;
    sf::Music music;
    // Operations
  public:
    SFMLClient ();
  protected:
    void init ();
    bool acquireControls ();
    void updateDisplay ();
  };

};

#endif

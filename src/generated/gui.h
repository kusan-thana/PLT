#ifndef GUI__H
#define GUI__H


namespace gui {

  enum GUITypeId {
    CURSOR,
    MOVE_RANGE,
    ACTIVE_TILE     = 3
  };

  /// class GUIElement - 
  class GUIElement {
    // Attributes
  protected:
    int x;
    int y;
    GUITypeId guiTypeId;
    bool active;
    // Operations
  public:
    GUIElement ();
    int getX ();
    int getY ();
    bool getActive ();
    virtual GUITypeId getGuiTypeId () = 0;
    virtual void setX ();
    virtual void setY ();
    virtual void setActive (bool active);
  };

  /// class Cursor - 
  class Cursor : public gui::GUIElement {
    // Attributes
  protected:
    state::Element* character;
    state::LevelState& levelState;
    // Operations
  public:
    Cursor (state::LevelState& levelState);
    ~Cursor ();
    state::Element*  getcharacter ();
    GUITypeId getGuiTypeId ();
    void setX (int x);
    setY (int y);
    void setActive (bool active);
    void setcharacter (state::Element* character);
  };

  /// class GUIEvent - 
  class GUIEvent {
    // Attributes
  public:
    GUI& gui;
    const GUIElementList& guiElementList;
    int idx;
    state::LevelState& levelState;
    // Operations
  public:
    GUIEvent (GUIElementList& guiElementList, int idx);
    ~GUIEvent ();
  };

  /// class GUIObserver - 
  class GUIObserver {
    // Operations
  public:
    virtual void guiChanged (const GUIEvent& e) = 0;
  };

  /// class GUIObservable - 
  class GUIObservable {
    // Associations
    // Attributes
  protected:
    std::vector<GUIObservers* o> observers;
    // Operations
  public:
    GUIObservable ();
    ~GUIObservable ();
    void registerObserver (GUIObserver* o);
    void unregisterObserver (GUIObserver* o);
    void notifyObserver (const GUIEvent& e);
  };

  /// class GUIElementList - 
  class GUIElementList : public gui::GUIObservable {
    // Associations
    // Attributes
  protected:
    GUI& gui;
    std::vector<GUIELement*> guiElements;
    // Operations
  public:
    GUIElementList (GUI& gui);
    GUI& getGui ();
    int size () const;
    GUIElement* getGuiELement (int i) const;
    GUIElement* getGuiElement (int x, int y) const;
    void setGuiElement (int i, GUIElement* guiElement);
    void notifyObservers (int i = -1) const;
    void clear ();
  };

  /// class GUIMoveRange - 
  class GUIMoveRange : public gui::GUIElementList {
    // Attributes
  protected:
    bool active;
    state::Element* element;
    // Operations
  public:
    GUIElementGrid (GUI& gui, length int, state::Element* element);
    bool getActive () const;
    void setActive (bool active);
    void setElement (state::Element* elemnt);
    void computeRange ();
  };

  /// class GUI - 
  class GUI : public gui::GUIObservable {
    // Associations
    // Attributes
  protected:
    state::LevelState& levelState;
    GUIElementList cursor;
    GUIMoveRange moveRange;
    engine::Engine& engine;
    bool startPlayerAI;
    // Operations
  public:
    GUI (state::LevelState& levelState);
    ~GUI ();
    GUIElementList& getCursorList ();
    GUIMoveRange& getMoveRange ();
    const state::LevelState& getLevelState () const;
    void setCursorList (GUIElementList& const cursor);
    void setMoveRange (GUIMoveRange& const moveRange);
    void commander (engine::Engine& engine);
    void setEngineMode (engine::EngineMode engineMode);
    void setStartPlayerAI (bool startPlayerAI);
    bool getStartPlayerAI ();
  };

  /// class GUITile - 
  class GUITile : public gui::GUIElement {
    // Operations
  public:
    Tile (int x, int y, GUITypeId guiTypeId);
    GUITypeId getGuiTypeId ();
  };

};

#endif

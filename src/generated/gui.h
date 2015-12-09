#ifndef GUI__H
#define GUI__H


namespace gui {

  enum GUITypeId {
    CURSOR     = 1,
    MOVE_RANGE     = 2
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
    virtual ~GUIElement ();
    int getX () const;
    int getY () const;
    bool getActive () const;
    virtual GUITypeId getGuiTypeId () const = 0;
    virtual void setX (int x);
    virtual void setY (int y);
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
    state::Element*  getCharacter ();
    GUITypeId getGuiTypeId () const;
    virtual void setX (int x);
    virtual void setY (int y);
    virtual void setActive (bool active);
    void setCharacter (state::Element* character);
  };

  /// class GUIEvent - 
  class GUIEvent {
    // Attributes
  public:
    GUI& gui;
    GUIElementList& guiElementList;
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
    virtual ~GUIObserver ();
    virtual void guiChanged (const GUIEvent& e) = 0;
  };

  /// class GUIObservable - 
  class GUIObservable {
    // Associations
    // Attributes
  protected:
    std::vector<GUIObservers> observers;
    // Operations
  public:
    GUIObservable ();
    ~GUIObservable ();
    void registerObserver (GUIObserver* o);
    void unregisterObserver (GUIObserver* o);
    void notifyObserver (const GUIEvent& o);
  };

  /// class GUIElementList - 
  class GUIElementList : public gui::GUIObservable {
    // Associations
    // Attributes
  protected:
    GUI& gui;
    std::vector<GUIElement*> guiElements;
    // Operations
  public:
    GUIElementList (GUI& gui);
    GUI& getGui ();
    int size () const;
    GUIElement* getGuiElement (int i) const;
    GUIElement* getGuiElement (int x, int y) const;
    void setGuiElement (int i, GUIElement* guiElement);
    void notifyObservers (int i = -1) const;
    void clear ();
  };

  /// class GUIMoveRange - 
  class GUIMoveRange : public gui::GUIElementList {
    // Attributes
  protected:
    state::Element* element;
    // Operations
  public:
    GUIMoveRange (GUI& gui);
    void setElement (state::Element* elemnt);
    void computeRange ();
  };

  /// class GUI - 
  class GUI : public gui::GUIObservable {
    // Associations
    // Attributes
  public:
    engine::EngineMode engineMode;
  protected:
    state::LevelState& levelState;
    GUIElementList cursorList;
    GUIMoveRange moveRange;
    engine::Engine& engine;
    bool startPlayerAI;
    // Operations
  public:
    GUI (state::LevelState& levelState, engine::Engine& );
    ~GUI ();
    GUIElementList& getCursorList ();
    GUIMoveRange& getMoveRange ();
    state::LevelState& getLevelState ();
    void setCursorList (const GUIElementList& cursor);
    void setMoveRange (GUIMoveRange& const moveRange);
    void commander (engine::Engine& engine);
    void setEngineMode (engine::EngineMode engineMode);
    void setStartPlayerAI (bool startPlayerAI);
    bool getStartPlayerAI ();
    void init ();
  };

  /// class GUITile - 
  class GUITile : public gui::GUIElement {
    // Operations
  public:
    GUITile (int x, int y, GUITypeId guiTypeId);
    GUITypeId getGuiTypeId ();
  };

};

#endif

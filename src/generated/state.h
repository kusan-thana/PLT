#ifndef STATE__H
#define STATE__H


namespace state {

  enum TypeID {
    SPACE     = 1,
    OBSTACLE     = 2,
    HERO     = 3,
    BRUTE     = 4,
    HEALER     = 5,
    WIZARD     = 6,
    MINION     = 7,
    BOSS     = 8
  };

  enum Direction {
    NONE     = 0,
    NORTH     = 1,
    SOUTH     = 2,
    EAST     = 3,
    WEST     = 4
  };

  /// class Element - 
  class Element {
    // Associations
    // Attributes
  protected:
    int x;
    int y;
    TypeID IDElement;
    Direction orientation;
    /// "True" quand l'element est survole
    bool active;
    int x_origin;
    int y_origin;
    // Operations
  public:
    /// Constructeur
    Element ();
    /// Destructeur
    virtual ~Element ();
    virtual bool isStatic () const = 0;
    virtual Element* clone () const = 0;
    virtual TypeID getTypeID () const;
    int getX () const;
    int getY () const;
    Direction getDirection () const;
    void setX (int x);
    void setY (int y);
    void setDirection (Direction orientation);
    bool isActive () const;
    void setActive (bool active);
  };

  enum Status {
    NORMAL,
    SUPER
  };

  /// class MobileElement - 
  class MobileElement : public state::Element {
    // Associations
    // Attributes
  protected:
    Status status;
    int speed;
    /// Health Point : Nombre de point de vie
    int HP;
    /// Point d'attaque
    int attackPt;
    /// Point de défense
    int defensePt;
    /// Nombre  d'action par tour
    int nbAction;
    /// Nombre de cases de déplacement possible par tour
    int nbStep;
    /// 	
    int level;
    int experience;
    bool turnPlayed;
    int position;
    bool movePlayed;
    // Operations
  public:
    MobileElement ();
    /// Renvoi "false"
    bool isStatic () const;
    virtual bool isPlayerCharacter () const = 0;
    int getNbStep () const;
    int getNbAction () const;
    bool getTurnPlayed () const;
    void setTurnPlayed (bool turnPlayed);
    void setNbAction (int nbAction);
    void setHP (int HP);
    int getHP () const;
    int getAttackPt () const;
    void setAttackPt (int attackPt);
    int  getDefensePt () const;
    void setDefensePt (int defensePt);
    bool getMovePlayed () const;
    void setMovePlayed (bool attackPlayed);
  };

  /// class StaticElement - 
  class StaticElement : public state::Element {
    // Operations
  public:
    /// Renvoi "true"
    bool isStatic () const;
    virtual bool isSpace () const;
  };

  /// class PlayerCharacter - 
  class PlayerCharacter : public state::MobileElement {
    // Attributes
  protected:
    /// Nombre de points de magie
    int mana;
    // Operations
  public:
    PlayerCharacter (TypeID id);
    Element* clone () const;
    Status getStatus () const;
    bool isPlayerCharacter () const;
  };

  /// class Monster - 
  class Monster : public state::MobileElement {
    // Operations
  public:
    Monster (TypeID id);
    Element* clone () const;
    Status getStatus () const;
    bool isPlayerCharacter () const;
  };

  enum ObstacleTypeID {
    WALL,
    STONE,
    TREE,
    FIR,
    WATER
  };

  /// class Obstacle - 
  class Obstacle : public state::StaticElement {
    // Associations
    // Attributes
  protected:
    ObstacleTypeID IDObstacle;
    // Operations
  public:
    Obstacle (ObstacleTypeID id);
    /// Renvoi false
    bool isSpace () const;
    Element* clone () const;
    ObstacleTypeID getObstableTypeID () const;
    void setObstacleTypeID (ObstacleTypeID id);
  };

  enum SpaceTypeID {
    GRASS,
    START,
    ENERGY
  };

  /// class Space - 
  class Space : public state::StaticElement {
    // Associations
    // Attributes
  protected:
    SpaceTypeID IDSpace;
    // Operations
  public:
    Space (SpaceTypeID id);
    /// Renvoi "true"
    bool isSpace () const;
    Element* clone () const;
    SpaceTypeID getSpaceTypeID () const;
    void setSpaceTypeID (SpaceTypeID id);
  };

  enum LevelStateEventID {
    ALL_CHANGED,
    LEVEL_CHANGED,
    EPOCH_CHANGED,
    LIST_CHANGED
  };

  /// class LevelStateEvent - 
  class LevelStateEvent {
    // Associations
    // Attributes
  public:
    const LevelState& levelState;
  protected:
    LevelStateEventID id;
    // Operations
  public:
    LevelStateEvent (const LevelState&  levelState, LevelStateEventID id);
    bool operator== (LevelStateEventID id) const;
    bool operator!= (LevelStateEventID id) const;
  };

  /// class LevelStateObserver - 
  class LevelStateObserver {
    // Operations
  public:
    virtual void levelStateChanged (const LevelStateEvent& levelStateEvent) = 0;
  };

  /// class Observable - 
  class Observable {
    // Associations
    // Attributes
  protected:
    std::vector<LevelStateObserver*> observers;
    // Operations
  public:
    virtual ~Observable ();
    void registerObserver (LevelStateObserver* o);
    void notifyObservers (const LevelStateEvent& e);
  };

  /// class ElementFactory - 
  class ElementFactory {
    // Attributes
  protected:
    std::unordered_map<char,AElementAlloc*> list;
    // Operations
  public:
    ~ElementFactory ();
    Element* newInstance (char id) const;
    void registerType (char id, AElementAlloc* a);
  };

  /// class ElementList - Contient le nombre d'éléments instanciés
  class ElementList : public state::Observable {
    // Associations
    // Attributes
  protected:
    LevelState& levelState;
    ElementFactory* factory;
    std::vector<Element*> elements;
    // Operations
  public:
    ElementList (LevelState& levelState);
    ~ElementList ();
    ElementList* clone () const;
    void copy (const ElementList& list);
    const LevelState& getLevelState () const;
    int size () const;
    Element* getElement (int i) const;
    state::Element* getElement (int x, int y);
    void clear ();
    void setElementFactory (ElementFactory* factory);
    void setElement (int i, Element* element);
    void removeElement (int i);
    void removeElement (Element* element);
    int numberOfPlayer ();
    int numberOfMonster ();
  };

  /// class ElementGrid - Gère l'emplacement des éléments sur la grille
  class ElementGrid : public state::ElementList {
    // Attributes
  protected:
    int width;
    int height;
    // Operations
  public:
    ElementGrid (LevelState& levelState);
    ElementGrid* clone () const;
    void copy (const ElementGrid& grid);
    int getWidth () const;
    int getHeight () const;
    /// Renvoi l'élément de la cellule selectionnee
    /// @param i		(???) 
    /// @param j		(???) 
    Element* getCell (int i, int j) const;
    /// Place l'element sur la cellule selectionnee
    /// @param i		(???) 
    /// @param j		(???) 
    /// @param e		(???) 
    void setCell (int i, int j, Element* e);
    void load (const char* file_name);
  };

  enum TurnToPlay {
    PLAYER     = 0,
    OPPONENT     = 1
  };

  enum WorldTypeID {
    LEVEL     = 1
  };

  /// class ElementWorld - 
  class ElementWorld {
    // Associations
    // Attributes
  protected:
    int x;
    int y;
    WorldTypeID IDWorldElement;
    bool active;
    // Operations
  public:
    int const getX ();
    int const getY ();
    void setX (int x);
    void setY (int y);
  };

  /// class ElementListWorld - 
  class ElementListWorld {
    // Associations
    // Attributes
  protected:
    WorldState& worldState;
    std::vector<ElementWorld*> worldElements;
    // Operations
  public:
    ElementListWorld (WorldState& worldState);
    WorldState& getWorldState () const;
    int const size ();
    ElementWorld* getElement (int i) const;
    void clear ();
    void setElement (int i, ElementWorld* element);
  };

  /// class WorldState - 
  class WorldState {
    // Associations
    // Attributes
  protected:
    ElementWorldList elementListWorld;
    int epoch;
    float epochRate;
    int nbLockedLevelLeft;
    // Operations
  public:
    WorldState ();
    int const getEpoch ();
    float const getEpochRate ();
    void setEpoch (int time);
    void setEpochRate (float rate);
  };

  enum StateType {
    LEVELSTATE     = 1,
    WORLDSTATE     = 2
  };

  /// class State - 
  class State {
    // Associations
    // Attributes
  protected:
    LevelState levelState;
    WorldState worldState;
    StateType currentState;
    // Operations
  public:
    ~State ();
  };

  /// class LevelState - 
  class LevelState : public state::Observable {
    // Associations
    // Attributes
  protected:
    ElementList characters;
    ElementGrid grid;
    int epoch;
    float epochRate;
    TurnToPlay turnToPlay;
    /// Nombre de personnage restant dans l’équipe joueur 
    int nbPlayerCharLeft;
    /// Nombre de personnage restant dans l’équipe ennemi 
    int nbOpponentCharLeft;
    // Operations
  public:
    LevelState ();
    LevelState* clone () const;
    void copy (const LevelState& levelState);
    int getEpoch () const;
    float getEpochRate () const;
    const ElementGrid& getElementGrid () const;
    ElementGrid& getElementGrid ();
    const ElementList& getElementList () const;
    ElementList& getElementList ();
    MobileElement* getMobileElem ();
    TurnToPlay getTurnToPlay () const;
    void setElementFactory (ElementFactory* factory);
    void setEpoch (int epoch);
    void setEpochrate (float rate);
    void loadLevel (const char* file_name);
  };

  /// class AElementAlloc - 
  class AElementAlloc {
    // Associations
    // Operations
  public:
    virtual ~AElementAlloc ();
    virtual Element* newInstance () = 0;
  };

  /// class ElementAlloc - 
  template <  class E,   typename ID>
  class ElementAlloc : public state::AElementAlloc {
    // Attributes
  protected:
    ID id;
    // Operations
  public:
    ElementAlloc (ID id);
    Element* newInstance ();
  };

  enum DifficultyLevel {
    EASY     = 1,
    MEDIUM     = 2,
    HARD     = 3
  };

  /// class ElementLevel - 
  class ElementLevel : public state::ElementWorld {
    // Associations
    // Attributes
  protected:
    DifficultyLevel difficultyLevel;
    bool locked;
    // Operations
  public:
    bool const islocked ();
    void unlock ();
  };

  /// class LevelListEvent - 
  class LevelListEvent : public state::LevelStateEvent {
    // Attributes
  public:
    const Element& list;
    int idx;
    // Operations
  public:
    LevelListEvent (const ElementList& list, int idx);
  };

};

#endif

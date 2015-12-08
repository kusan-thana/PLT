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
    state::TypeID IDElement;
    // Attributes
  public:
    int x_origin;
    int y_origin;
  protected:
    int x;
    int y;
    Direction orientation;
    /// "True" quand l'element est survole
    bool active;
    // Operations
  public:
    /// Constructeur
    Element ();
    /// Destructeur
    virtual ~Element ();
    virtual bool const isStatic () = 0;
    virtual Element* const clone () = 0;
    virtual TypeID const getTypeID ();
    int const getX ();
    int const getY ();
    Direction const getDirection ();
    void setX (int x);
    void setY (int y);
    void setDirection (Direction orientation);
    bool const isActive ();
    void setActive (bool active);
  };

  enum Status {
    NORMAL,
    SUPER
  };

  /// class MobileElement - 
  class MobileElement : public state::Element {
    // Associations
    state::Status status;
    // Attributes
  protected:
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
    bool const isStatic ();
    virtual bool const isPlayerCharacter () = 0;
    int const getNbStep ();
    int const getNbAction ();
    bool const getTurnPlayed ();
    void setTurnPlayed (bool turnPlayed);
    void setNbAction (int nbAction);
    void setHP (int HP);
    int const getHP ();
    int const getAttackPt ();
    void setAttackPt (int attackPt);
    void const getDefensePt ();
    void setDefensePt (int defensePt);
    bool const getMovePlayed ();
    void setMovePlayed (bool attackPlayed);
  };

  /// class StaticElement - 
  class StaticElement : public state::Element {
    // Operations
  public:
    /// Renvoi "true"
    bool const isStatic ();
    virtual bool const isSpace ();
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
    Element* const clone ();
    Status const getStatus ();
    bool const isPlayerCharacter ();
  };

  /// class Monster - 
  class Monster : public state::MobileElement {
    // Operations
  public:
    Monster (TypeID id);
    Element* const clone ();
    Status const getStatus ();
    bool const isPlayerCharacter ();
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
    state::ObstacleTypeID IDObstacle;
    // Operations
  public:
    Obstacle (ObstacleTypeID id);
    /// Renvoi false
    bool const isSpace ();
    Element* const clone ();
    ObstacleTypeID const getObstableTypeID ();
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
    state::SpaceTypeID IDSpace;
    // Operations
  public:
    Space (SpaceTypeID id);
    /// Renvoi "true"
    bool const isSpace ();
    Element* const clone ();
    SpaceTypeID const getSpaceTypeID ();
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
    state::LevelStateEventID id;
    // Attributes
  public:
    const LevelState& levelState;
    // Operations
  public:
    LevelStateEvent (const LevelState&  levelState, LevelStateEventID id);
    bool const operator== (LevelStateEventID id);
    bool const operator!= (LevelStateEventID id);
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
    void notifyObservers (const LevelStateEvent& e e);
  };

  /// class ElementFactory - 
  class ElementFactory {
    // Attributes
  protected:
    std::map<char,AElementAlloc*> list;
    // Operations
  public:
    ~ElementFactory ();
    Element* const newInstance (char id);
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
    ElementList* const clone ();
    void copy (const ElementList& list);
    const LevelState& const getLevelState ();
    int const size ();
    Element* const getElement (int i);
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
    ElementGrid* const clone ();
    void copy (const ElementGrid& grid);
    int const getWidth ();
    int const getHeight ();
    /// Renvoi l'élément de la cellule selectionnee
    /// @param i		(???) 
    /// @param j		(???) 
    Element* const getCell (int i, int j);
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
     IDWorldElement;
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
    WorldState& const getWorldState ();
    int const size ();
    ElementWorld* const getElement (int i);
    void clear ();
    void setElement (int i, ElementWorld* element);
  };

  /// class WorldState - 
  class WorldState {
    // Associations
    // Attributes
  protected:
    WorldElementList worldElementList;
    int epoch;
    float epochRate;
     nbLockedLevelLeft;
    // Operations
  public:
    worldState ();
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
    ~State State ();
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
    LevelState* const clone ();
    void copy (const LevelState& levelState);
    int const getEpoch ();
    float const getEpochRate ();
    const ElementGrid& const getElementGrid ();
    ElementGrid& getElementGrid ();
    const ElementList& const getElementList ();
    ElementList& getElementList ();
    MobileElement* getMobileElem ();
    TurnToPlay const getTurnToPlay ();
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
    virtual Element* newInstance ();
  };

  /// class ElementAlloc - 
  template <  classe E,   typename ID>
  class ElementAlloc : public state::AElementAlloc {
    // Attributes
  protected:
    ID id;
    // Operations
  public:
    ElementAlloc (ID id);
    Element* newInstance ();
  };

  enum LevelType {
    NORMAL     = 1,
    BOSS     = 2
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
    LevelType levelType;
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

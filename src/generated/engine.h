#ifndef ENGINE__H
#define ENGINE__H


namespace engine {

  /// class Command - 
  class Command {
    // Attributes
  public:
     ;
    // Operations
  public:
    virtual ~Command ();
    virtual CommandTypeId const getTypeId () = 0;
  };

  /// class CommandTypeId - 
  class CommandTypeId {
    // Associations
    // Attributes
  public:
     Main;
     Mode;
     Selection;
     Actif;
  };

  /// class MoveCommand - 
  class MoveCommand : public engine::Command {
    // Attributes
  protected:
    int x;
    int y;
    state::Element* character;
    // Operations
  public:
    MoveCommand (int x, int y, state::Element* character);
    ~MoveCommand ();
    CommandTypeId const getTypeId ();
    int const getPositionX ();
    int getPositionY ();
    void setPosition (int x, int y);
    state::Element* getCharacter ();
  };

  /// class LoadCommand - 
  class LoadCommand : public engine::Command {
    // Attributes
  protected:
    std::string file_name;
    // Operations
  public:
    LoadCommand (const char* f);
    CommandTypeId const getTypeId ();
    const char* const getFileName ();
  };

  enum EngineMode {
    PLAY,
    RECORD,
    REPLAY
  };

  /// class ModeCommand - 
  class ModeCommand : public engine::Command {
    // Attributes
  protected:
    /// 	
    EngineMode mode;
    // Operations
  public:
    ModeCommand (EngineMode mode);
    CommandTypeId const getTypeId ();
    EngineMode const getMode ();
  };

  enum modeActivate {
    DIRECTION     = 1,
    POSITION     = 2
  };

  /// class CommandSet - 
  class CommandSet {
    // Associations
    // Attributes
  protected:
    std::unordered_map<int, Command*> commandList;
    // Operations
  public:
    ~CommandSet ();
    int const size ();
    Command* const get (int category);
    void set (Command* cmd);
    void clear ();
  };

  /// class Action - 
  class Action {
    // Operations
  public:
    virtual ~Action ();
    apply (state::LevelState& levelState);
    void undo ();
  };

  /// class ActionList - 
  class ActionList {
    // Associations
    // Attributes
  protected:
    state::LevelState& levelState;
    std::vector<Action*> actions;
    // Operations
  public:
    ActionList (state::LevelState& levelState);
    int const size ();
    Action* const get (int i);
    void apply ();
    void add (Action* action);
  };

  /// class Record - 
  class Record {
    // Attributes
  protected:
    state::LevelState& mainLevelState;
    state::LevelState* initLevelState;
    state::LevelState* lastLevelState;
    std::vector<ActionList*> actions;
    // Operations
  public:
    Record (state::LevelState& levelState);
    ~Record ();
    void startRecord ();
    void stopRecord ();
  };

  /// class Engine - 
  class Engine {
    // Associations
    engine::EngineMode mode;
    engine::Record record;
    // Attributes
  public:
    EngineMode engineMode;
    ActionList actions;
  protected:
    state::LevelState levelState;
    CommandSet commandSet;
    // Operations
  public:
    Engine ();
    ~Engine ();
    void addCommand (engine::Command cmd);
    void update ();
    EngineMode getMode ();
    void turnGestion ();
  protected:
    setMode (EngineMode mode);
  };

  /// class Ruler - 
  class Ruler {
    // Associations
    // Attributes
  public:
    ActionList& actions;
  protected:
    const CommandSet& commands;
    const state::LevelState& curr_LevelState;
    // Operations
  public:
    Ruler (CommandSet& , state::LevelState& );
    ~Ruler ();
    void apply ();
  };

  /// class MoveCharacter - 
  class MoveCharacter : public engine::Action {
    // Attributes
  protected:
    state::Element* character;
     x;
     y;
    // Operations
  public:
    void MoveCharacter (state::Element* character, int x, int y, state::LevelState& levelState);
    void apply (state::LevelState& levelState);
    /// 	
    /// @param levelState		(???) 
    void undo (state::LevelState& levelState);
  };

  /// class IncEpoch - 
  class IncEpoch : public engine::Action {
    // Operations
  public:
    IncEpoch ();
    void apply (state::LevelState& levelState);
    void undo (state::LevelState levelState);
  };

  /// class AttackCommand - 
  class AttackCommand : public engine::Command {
    // Attributes
  public:
    state::MobileElement* attacker;
    state::MobileElement* target;
    // Operations
  public:
    AttackCommand (state::Element* attacker, state::Element* target);
    ~AttackCommand ();
    state::Element* getAttacker ();
    state::Element* getTarget ();
    commandTypeId const getTypeId ();
  };

  /// class AttackCharacter - 
  class AttackCharacter : public engine::Action {
    // Attributes
  public:
    state::MobileElement* attacker;
    state::MobileElement* target;
    // Operations
  public:
    AttackCharacter (state::MobileElement* attacker, state::MobileElement* target, state::LevelState& levelState);
    ~AttackCharacter ();
    void apply (state::LevelState& levelState);
    void undo (state::LevelState& levelState);
  };

  /// class EndTurnAction - 
  class EndTurnAction : public engine::Action {
    // Attributes
  public:
    state::Element* character;
    // Operations
  public:
    EndTurnAction (state::Element* character);
    ~EndTurnAction ();
    void apply (state::LevelState& levelState);
    void undo (state::LevelState levelState);
  };

  /// class EndTeamTurn - 
  class EndTeamTurn {
    // Attributes
  protected:
    /// 				
    TurnToPlay lastTurnToPlay;
    // Operations
  public:
    EndTeamTurn ();
    ~EndTeamTurn ();
    void apply (state::LevelState& levelState);
    void undo (state::LevelState& levelState);
  };

};

#endif
namespace state {

  /// class LevelStateObserver - 
  class LevelStateObserver {
    // Operations
  public:
    virtual void levelStateChanged (const LevelStateEvent& ) = 0;
  };

};


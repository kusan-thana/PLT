namespace gui_state {

  /// class GUIObserver - 
  class GUIObserver {
    // Operations
  public:
    virtual void guiChanged (const GUIEvent& ) = 0;
  };

};


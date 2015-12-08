#ifndef GUI_STATE__H
#define GUI_STATE__H

namespace gui_state {

  /// class GUIObserver - 
  class GUIObserver {
    // Operations
  public:
    virtual void guiChanged (const GUIEvent& ) = 0;
  };

};

#endif

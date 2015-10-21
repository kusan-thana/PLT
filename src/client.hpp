#ifndef Client_H
#define Client_H
#include "sfmlsurface.hpp"
#include "scene.hpp"
#include "layer.hpp"
class Client {
	
	protected:
		render::Scene scene;

		Client();
		virtual void init();
		virtual bool acquireControls() = 0;
		//virtual void stateChanged() = 0;
		virtual void updateDisplay() = 0;
		
	public:
		void run();

};

#endif

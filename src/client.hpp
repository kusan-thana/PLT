#ifndef Client_H
#define Client_H
#include "sfmlSurface.hpp"
#include "scene.hpp"
#include "layer.hpp"

namespace client {

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
}
#endif

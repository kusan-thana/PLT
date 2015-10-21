#ifndef Client_H
#define Client_H

class Client {
	
	protected:
		virtual bool acquireControls() =0;
		//virtual void stateChanged() =0;
		virtual void updateDisplay() =0;
		void run();

};

#endif

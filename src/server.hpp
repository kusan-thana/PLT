#pragma once

#include "engine.hpp"

namespace server {
	class Server {
	protected:
//		engine::Engine engine;
	public:
		virtual ~Server();
		virtual void run() = 0;
	};
}


#pragma once

#include "Engine.hpp"

namespace server {
	class Server {
	protected:
		engine::Engine engine;
	public:
		virtual ~Server();
		virtual void Server::run() = 0;
	};
}

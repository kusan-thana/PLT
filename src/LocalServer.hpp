#pragma once

#include "server.hpp"

namespace server {
	class LocalServer : public Server {
	public:
		LocalServer();
		~LocalServer();
		void LocalServer::run();

	};
}

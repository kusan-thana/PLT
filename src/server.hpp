#ifndef Server_H
#define Server_H
#include "engine.hpp"
#include "state.hpp"

namespace server {
	class Server;
	class LocalServer;
	class Observable;
	class ServerObserver;
	enum ServerEvent : unsigned int;
}

#include "generated/server.h"

#endif

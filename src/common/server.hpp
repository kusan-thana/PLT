#ifndef Server_H
#define Server_H
#include <thread>
#include <mutex>
#include "engine.hpp"
#include "state.hpp"
#include "ai.hpp"
#include <json/json.h>

namespace server {
	class Server;
	class LocalServer;
	class Observable;
	class ServerObserver;
	enum ServerEvent : unsigned int;
}

#include "generated/server.h"

#endif

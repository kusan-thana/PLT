#ifndef Server_H
#define Server_H
#include <iostream>
#include <thread>
#include <mutex>
#include "engine.hpp"
#include "state.hpp"
#include "ai.hpp"
#include <json/json.h>
#include <memory>
#include <unordered_map>
#include <stdexcept>

using std::unique_ptr;
using std::string;

namespace server {
	class Server;
	class LocalServer;
	class Observable;
	class ServerObserver;
	class RemoteServer;
	enum ServerEvent : unsigned int;
}

#include "../generated/server.h"

namespace server {
template<class T,typename ... Args>
	std::unique_ptr<T> make_unique(Args ... args) {
    return std::unique_ptr<T>(new T(args ...));
}
}
#endif

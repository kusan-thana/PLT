#pragma once

#include "levelstate.hpp"
#include "commandset.hpp"

namespace engine {
	class Ruler
	{
	public:
		Ruler(CommandSet&, const state::LevelState&);
		~Ruler();
	};
}

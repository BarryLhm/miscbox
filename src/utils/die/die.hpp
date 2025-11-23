#pragma once
#include <cstdint>

#include "common.hpp"

namespace mbox::utils::die {
	enum class DeathType : std::uint8_t {
		SEGV,
		RAISE
	};
	MuResult die(DeathType type, int x);
}

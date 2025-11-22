#pragma once
#include <cstdint>

#include "common.hpp"

namespace mbox::utils::die {
	enum class DEATH_TYPE : std::uint8_t {
		SEGV,
		RAISE
	};
	M_RESULT die(DEATH_TYPE type, int x);
}

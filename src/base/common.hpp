#pragma once
#include <cstdint>

enum class MuResult : std::int8_t {
	SUCCESS = 0,
	FAILED = -1,
	INVALID = -2
};

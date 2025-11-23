#include <csignal>
#include <iostream>

#include "common.hpp"
#include "die.hpp"

namespace mbox::utils::die {
	MuResult die(DeathType type, int x)
	{
		switch (type) {
		case DeathType::SEGV:
			if (x != 0) return MuResult::INVALID;
			{
				volatile int* nurupo = nullptr;
				*nurupo = 114514;
			}
			return MuResult::FAILED;
		case DeathType::RAISE: raise(x);
		default: return MuResult::INVALID;
		}
		return MuResult::FAILED;
	}
}

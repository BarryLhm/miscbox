#include <common.hpp>
#include "die.hpp"

#include <iostream>
#include <csignal>

namespace mbox::utils::die {
	M_RESULT die(DEATH_TYPE type, int x) {
		switch (type) {
		case SEGV:
			if (x != 0) return R_INVALID;
			{ volatile int *nurupo = nullptr; *nurupo = 114514; }
			return R_FAILED;
		case RAISE: raise(x);
		default: return R_INVALID;
		}
		return R_FAILED;
	}
}

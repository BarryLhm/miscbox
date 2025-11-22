#include <csignal>
#include <iostream>

#include "common.hpp"
#include "die.hpp"

namespace mbox::utils::die {
	M_RESULT die(DEATH_TYPE type, int x)
	{
		switch (type) {
		case DEATH_TYPE::SEGV:
			if (x != 0) return M_RESULT::INVALID;
			{
				volatile int* nurupo = nullptr;
				*nurupo = 114514;
			}
			return M_RESULT::FAILED;
		case DEATH_TYPE::RAISE: raise(x);
		default: return M_RESULT::INVALID;
		}
		return M_RESULT::FAILED;
	}
}

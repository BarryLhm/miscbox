#include "die.h"

#include <iostream>
int die(DEATH_TYPE type) {
	volatile int *nurupo = nullptr;
	switch (type) {
	case SEGV:
		*nurupo = 114514;
		return -1;
	default: return -1;
	}
	return -1;
}

#include "die.h"

#include <iostream>
int die(DEATH_TYPE type) {
	switch (type) {
	case SEGV: { volatile int *nurupo = nullptr; *nurupo = 114514; }
	default: return -1;
	}
	return -1;
}

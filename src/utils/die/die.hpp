namespace mbox::utils::die {
	enum DEATH_TYPE {
		SEGV, RAISE
	};
	M_RESULT die(DEATH_TYPE type, int x);
}

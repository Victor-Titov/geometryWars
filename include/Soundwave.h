#pragma once
#include "Bullet.h"

class Soundwave : public Bullet {
public:
	Soundwave();
	~Soundwave();
	void init(Drawable drawable, int velocity, int angle);
private:
	void moveEntity();
	float m_dissopationRate;
	float m_trueHeight;
	int counter = 0;
};
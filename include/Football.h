#pragma once
#include "Bullet.h"
class Football : public Bullet {
public:
	Football();
	~Football();
private:
	void moveEntity();
	float m_yOffset = 1;
	float m_xOffset = 1;
};
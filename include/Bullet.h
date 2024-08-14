#pragma once
#include "Entity.h"
class Bullet : public Entity {
public:
	void init(Drawable drawable, int velocity, int angle);
	void update();
protected:
	void moveEntity();
	
};
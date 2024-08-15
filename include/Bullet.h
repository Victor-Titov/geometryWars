#pragma once
#include "Entity.h"
class Bullet : public Entity {
public:
	virtual void init(Drawable drawable, int velocity, int angle);
	void update();
protected:
	virtual void moveEntity();
	
};
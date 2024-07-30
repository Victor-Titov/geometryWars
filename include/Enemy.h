#pragma once
#include "Engine.h"
#include "Entity.h"
class Enemy : public Entity
{
public:
	void init(Drawable drawable, int velocity, double starting_angle);
	void update();
	void reset();
	
private:
		
	
	void home();
	
};

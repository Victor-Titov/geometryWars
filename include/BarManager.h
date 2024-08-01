#pragma once
#include "defines.h"
#include "Engine.h"

class Bar
{
public:
	Bar();
	~Bar();

	void init(string configFile);
	void update();
	void draw();
	void destroy();
	void setBar(int currNum, int maxNum);


private:

	Drawable blackBar;
	Drawable colouredBar;
	double original_width;
};
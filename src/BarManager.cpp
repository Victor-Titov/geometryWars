#include "BarManager.h"
#include "Engine.h"
#include "inputManager.h"
#include "Presenter.h"

Bar::Bar()
{
}

Bar::~Bar()
{
}

void Bar::init(string configFile)
{
	string tmp, textureImgPathBar1, textureImgPathBar2;

	fstream stream;

	stream.open(CONFIG_FOLDER + configFile);
	stream >> tmp >> textureImgPathBar1;
	stream >> tmp >> blackBar.rect.x >> blackBar.rect.y >> blackBar.rect.w >> blackBar.rect.h;
	stream >> tmp >> textureImgPathBar2;
	stream >> tmp >> colouredBar.rect.x >> colouredBar.rect.y >> colouredBar.rect.w >> colouredBar.rect.h;
	stream.close();

	blackBar.texture = loadTexture(textureImgPathBar1);
	colouredBar.texture = loadTexture(textureImgPathBar2);

	original_width = colouredBar.rect.w;
}

void Bar::update()
{
}

void Bar::draw()
{
	drawObject(blackBar);
	drawObject(colouredBar);
}

void Bar::destroy()
{
	SDL_DestroyTexture(blackBar.texture);
	SDL_DestroyTexture(colouredBar.texture);
}

void Bar::setBar(int currNum, int maxNum)
{
	colouredBar.rect.w = original_width * currNum / maxNum;
}


#include "Engine.h"

SDL_Texture* LoadTexture(string imgPath, SDL_Renderer* renderer)
{
	string tmpImg = IMG_FOLDER + imgPath;
	//tmpImg = IMG_FOLDER + "No.bmp";

	SDL_Surface* loadingSurface = SDL_LoadBMP(tmpImg.c_str());

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadingSurface);

	if (texture == nullptr)
	{
		cout << "ERROR IN LOADING PHOTO WITH PATH" << tmpImg;

		tmpImg = "img\\Null.bmp";

		loadingSurface = SDL_LoadBMP(tmpImg.c_str());


		texture = SDL_CreateTextureFromSurface(renderer, loadingSurface);
	}

	SDL_FreeSurface(loadingSurface);

	return texture;
}

bool isMouseInRect(int2 mouseCoor, SDL_Rect rect)
{
	if (mouseCoor.x >= rect.x && mouseCoor.x <= rect.x + rect.w && 
		mouseCoor.y >= rect.y && mouseCoor.y <= rect.y + rect.h)
	{
		return true;
	}

	return false;
}

bool collRectRect(SDL_Rect rect1, SDL_Rect rect2)
{
	if (rect1.x + rect1.w < rect2.x || rect1.x > rect2.x + rect2.w || rect1.y + rect1.h < rect2.y || rect1.y > rect2.y + rect2.h)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool CollCircleCircle(float2 center1, int circleR1, float2 center2, int circleR2)
{
	float dist, distY, distX;
	distX = abs(center1.x - center2.x);
	distY = abs(center1.y - center2.y);
	dist = sqrt(distX * distX + distY * distY);
	if (dist < (circleR1 + circleR2)/2) {
		return true;
	}
	else {
		return false;
	}
	
}

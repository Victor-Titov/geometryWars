#pragma once

#include "Engine.h"

class Presenter
{
public:
	static SDL_Window* m_mainWindow;
	static SDL_Renderer* m_mainRenderer;

	static int m_SCREEN_WIDTH;
	static int m_SCREEN_HEIGHT;

	void init();
	void update();
	void draw();

	static void drawObject(SDL_Texture* texture);
	static void drawObject(Drawable& drawable);
	static void drawObject(DrawableSrcRect& drawableSrcRect);
	static void drawObjectEx(SDL_Texture* texture, double angle);
	static void drawObjectEx(Drawable& drawable, double angle);
	static void drawObjectEx(DrawableSrcRect& drawableSrcRect, double angle);

private:
	void improveRenderer();
};

template <typename Params>
void drawObject(Params& value)
{
	Presenter::drawObject(value);
}

template <typename Params1, typename Params2>
void drawObjectEx(Params1& value, Params2 value2)
{
	Presenter::drawObjectEx(value, value2);
}

SDL_Texture* loadTexture(string path);
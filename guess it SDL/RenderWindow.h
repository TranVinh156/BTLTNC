#ifndef RENDER_WINDOW_H_
#define RENDER_WINDOW_H_

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#include "Game.h"


const int SCREEN_WIDTH = 864;
const int SCREEN_HEIGHT = 518;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

const int DRAW_COLOR_KEY = 0xff;

namespace CommonFunc
{
	bool RenderWindow(const char* p_title, int p_width, int p_height);
	
	SDL_Texture* loadTexture(std::string p_path);
	SDL_Texture* LoadTexture(std::string p_path);
	void RenderTexture(SDL_Texture* p_text, float p_x, float p_y, int p_w = 0, int p_h = 0, SDL_Rect* rec = NULL, SDL_Rect* camera = NULL);

	void ClearRenderer();
	void RenderPresent();
	void CleanUp();
}



#endif // !RENDER_WINDOW_H_



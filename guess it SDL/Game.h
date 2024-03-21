#ifndef GAME_H_
#define GAME_H_

#pragma once

#include "RenderWindow.h"

const int MAX_NUM = 100, INVALID_NUMBER = -345;

const int TABLE_X0 = 29, TABLE_Y0 = 285, TABLE_X1 = 829, TABLE_Y1 = 493;
const int TABLE_ROW_NUM = 5, TABLE_COL_NUM = 20;

class Game
{
public:
	Game() {};
	~Game() {};
	bool LoadMedia();

	void HandleInput(SDL_Event& event);
	int GetNumberClick();
	bool CreateMenu();
	void RenderGame();
	int Guess();
	void check();
	void ResetGame();
	void Clean();
	bool isRunning() { return gameRunning; };
private:
	bool gameRunning = true;
	std::vector <SDL_Texture*> menuList;
	std::vector <SDL_Texture*> numberList;
	SDL_Texture* menu01 = NULL;
	SDL_Texture* menu02 = NULL;

	bool start_menu = true;
	bool main_menu = false;

	int x = 0; // Toạ độ của chuột
	int y = 0;

	int secret_num;
	int num_guess = 50;
	int left = 1;
	int right = 100;
	int answer = 1;
};


#endif // !GAME_H_

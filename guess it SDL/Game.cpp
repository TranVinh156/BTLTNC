#include "Game.h"


bool Game::LoadMedia()
{
	menu01 = CommonFunc::loadTexture("img/Game.png");
	if (menu01 == NULL)
	{
		return false;
	}
	menu02 = CommonFunc::loadTexture("img/Game_2.png");
	if (menu02 == NULL)
	{
		return false;
	}
	
	SDL_Texture* num;
	for (int i = 1; i <= 100; i++)
	{
		num = CommonFunc::LoadTexture("img/" + std::to_string(i) + ".bmp");
		if (num == NULL)
		{
			return false;
		}
		numberList.push_back(num);
		num == NULL;
	}
	return true;
}

void Game::HandleInput(SDL_Event& event)
{
	if (event.type == SDL_QUIT) gameRunning = false;
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (start_menu)
		{
			x = event.button.x;
			y = event.button.y;

			secret_num = GetNumberClick();
			std::cout << secret_num << std::endl;
			if (secret_num > 0)
			{
				start_menu = false;
				main_menu = true;
			}
			
		}
		if (main_menu)
		{
			
			
			x = event.button.x;
			y = event.button.y;
			check();
			std::cout << num_guess << std::endl;
			//num_guess = Guess();
			
		}
	}

}
void Game::check()
{
	if (x >= 70 && x <= 170 && y >= 370 && y <= 420)
	{
		right = num_guess - 1;
		num_guess = (right + left) / 2;
	}
	if (x >= 694 && x <= 794 && y >= 370 && y <= 420)
	{
		left = num_guess + 1;
		num_guess = (right + left) / 2;
	}
	if (x >= 382 && x <= 482 && y >= 370 && y <= 420)
	{
		main_menu = false;
		start_menu = true;
		ResetGame();
	}
}


void Game::ResetGame()
{
	left = 1;
	right = 100;
	num_guess = 50;
}

int Game::GetNumberClick()
{
	if (x<TABLE_X0 || x>TABLE_X1 || y<TABLE_Y0 || y>TABLE_Y1) return INVALID_NUMBER;
	int cellWidth = (TABLE_X1 - TABLE_X0) / TABLE_COL_NUM, cellHeight = (TABLE_Y1 - TABLE_Y0) / TABLE_ROW_NUM;
	int col = (x - TABLE_X0) / cellWidth, row = (y - TABLE_Y0) / cellHeight;
	return (row * TABLE_COL_NUM + col + 1);
}

bool Game::CreateMenu()
{
	menuList.push_back(menu01);
	menuList.push_back(menu02);

	if (menuList.size() < 1) return false;
	return true;
}

void Game::RenderGame()
{
	if (start_menu)
	{
		CommonFunc::RenderTexture(menu01, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	else
	{
		CommonFunc::RenderTexture(menu02, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		CommonFunc::RenderTexture(numberList.at(secret_num-1), 320, 115, 28, 25);
		CommonFunc::RenderTexture(numberList.at(num_guess-1), 570, 145, 28, 25);
	}

}

void Game::Clean()
{
	SDL_DestroyTexture(menu01);
	SDL_DestroyTexture(menu02);
	for (int i = 1; i <= 100; i++)
	{
		SDL_DestroyTexture(numberList.at(i));
		numberList.at(i) = NULL;
	}
	menu01 = NULL;
	menu02 = NULL;

}
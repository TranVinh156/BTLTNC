#include "RenderWindow.h"

bool CommonFunc::RenderWindow(const char* p_title, int p_width, int p_height)
{
	bool success = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "INIT SDL ERROR" << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		g_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_width, p_height, SDL_WINDOW_SHOWN);
		if (g_window == NULL)
		{
			std::cout << "CREATE WINDOW ERROR" << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
			if (g_screen == NULL)
			{
				std::cout << "CREATE RENDERER ERROR" << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(g_screen, DRAW_COLOR_KEY, DRAW_COLOR_KEY, DRAW_COLOR_KEY, DRAW_COLOR_KEY);
				int imgFlag = IMG_INIT_PNG;
				if (!IMG_Init(imgFlag) & imgFlag)
				{
					success = false;
					std::cout << "IMG ERROR" << IMG_GetError() << std::endl;
				}
			}
		}
	}

	return success;
}

SDL_Texture* CommonFunc::loadTexture(std::string p_path)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(g_screen, p_path.c_str());
	if (texture == NULL)
	{
		std::cout << "TEXTURE ERROR" << IMG_GetError() << std::endl;
	}
	return texture;
}

SDL_Texture* CommonFunc::LoadTexture(std::string p_path)
{
	//Khởi tạo là nullptr để tránh lỗi 'dangling pointer'
	SDL_Texture* texture = nullptr;
	//Nạp ảnh từ tên file (với đường dẫn)
	SDL_Surface* loadedImage = SDL_LoadBMP(p_path.c_str());
	//Nếu không có lỗi, chuyển đổi về dạng texture and và trả về
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(g_screen, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Đảm bảo việc chuyển đổi không có lỗi
		if (texture == nullptr) {
			std::cout << "TEXTURE ERROR" << SDL_GetError() << std::endl;
		}
	}
	else {
		std::cout << "TEXTURE ERROR" << SDL_GetError() << std::endl;
	}
	return texture;
}


void CommonFunc::RenderTexture(SDL_Texture* p_text, float p_x, float p_y, int p_w, int p_h, SDL_Rect* rec, SDL_Rect* camera)
{
	SDL_Rect dst = { p_x, p_y, p_w, p_h };
	if (rec != NULL)
	{
		dst.w = rec->w;
		dst.h = rec->h;
	}
	if (camera != NULL)
	{
		dst.x = dst.x - camera->x;
		dst.y = dst.y - camera->y;
	}
	SDL_RenderCopy(g_screen, p_text, rec, &dst);
}

void CommonFunc::ClearRenderer()
{
	SDL_SetRenderDrawColor(g_screen, DRAW_COLOR_KEY, DRAW_COLOR_KEY, DRAW_COLOR_KEY, DRAW_COLOR_KEY);
	SDL_RenderClear(g_screen);
}

void CommonFunc::RenderPresent()
{
	SDL_RenderPresent(g_screen);
}

void CommonFunc::CleanUp()
{
	SDL_DestroyWindow(g_window);
	SDL_DestroyRenderer(g_screen);
	g_window = NULL;
	g_screen = NULL;
	SDL_Quit();
	IMG_Quit();
}
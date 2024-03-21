#include <SDL.h>
#include <iostream>
#include "RenderWindow.h";

// Kích thước cửa sổ

int main(int argc, char* argv[]) {
    // Khởi tạo SDL
    Game main_game;
    if (!CommonFunc::RenderWindow("GAME", SCREEN_WIDTH, SCREEN_HEIGHT)) return -1;
    if (!main_game.LoadMedia()) return -1;
    if (!main_game.CreateMenu()) return -1;

    while (main_game.isRunning())
    {
        if (SDL_PollEvent(&g_event))
        {
            main_game.HandleInput(g_event);
        }
        CommonFunc::ClearRenderer();
        main_game.RenderGame();
        CommonFunc::RenderPresent();
        SDL_Delay(100);
    }

    main_game.Clean();
    CommonFunc::CleanUp();
    return 0;
}
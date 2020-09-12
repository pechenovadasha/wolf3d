#include "wolf.h"

void init(t_sdl *sdl)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        exit(-1);
    sdl->win = SDL_CreateWindow("Текстуры", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH_W, HEIGHT_W, SDL_WINDOW_SHOWN);
    if (sdl->win == NULL)
        exit(-1);
    sdl->ren = SDL_CreateRenderer(sdl->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (sdl->ren == NULL)
        exit(-1);
    SDL_SetRenderDrawColor(sdl->ren, 0xFF, 0xFF, 0xFF, 0xFF);
    int flags = IMG_INIT_PNG;
    sdl->surf = IMG_Load("wall0.png");
    if (sdl->surf == NULL)
        exit(-1);
    sdl->wall0 = SDL_CreateTextureFromSurface(sdl->ren, sdl->surf);
    if (sdl->wall0 == NULL)
        exit(-1);

}

void rendering(t_main *data, t_sdl *sdl)
{
    init(sdl);
    SDL_Event e;
    while(1)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                exit(0);
        }
        SDL_RenderClear(sdl->ren);
        SDL_RenderCopy(sdl->ren, sdl->wall0, NULL, NULL);
        SDL_RenderPresent(sdl->ren);
    }
}

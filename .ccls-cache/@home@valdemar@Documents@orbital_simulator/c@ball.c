#include <stdio.h>
#include <SDL2/SDL.h>

#define WIDTH 900
#define HEIGHT 600
//window does not open in wayland compositor, well hyprland for me 
//
int main()
{
  printf("ball pit open\n");
  SDL_Init(SDL_INIT_VIDEO); //clearify
  SDL_CreateWindow("ball pit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  SDL_Delay(3000);

}

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SDL_FLAGS SDL_INIT_VIDEO //why?

#define W_TITLE "open window"
#define W_WIDTH 800
#define W_HEIGHT 600
//given that we cannot know how big the memory allocation of the window will be,using the heap which is unstructured and adjustble memory is advised
struct Game {
  SDL_Window *window;
  SDL_Renderer *renderer;
};
//
bool game_init_sdl(struct Game *g); //forward declare functions so c compiler knows they exists befor running them in main
void game_free();

bool game_init_sdl(struct Game *g) { //tests if SDL is giving an error 
  if (!SDL_Init(SDL_FLAGS)) { //SDL returns 1 if working
    fprintf(stderr, "Error Intializing SDL3: %s\n", SDL_GetError());
    return false;
  }

  g->window = SDL_CreateWindow(W_TITLE, W_WIDTH, W_HEIGHT, 0); //acess the member window of pointer g and set it equal to SDL_CreateWindow
  if (!g->window) {
    fprintf(stderr, "Error creating Window: %s\n", SDL_GetError());
    return false;
  }
  return true;
}

void game_free() {
  SDL_Quit();
}

int main(void){
  bool exit_status = EXIT_FAILURE;

  if (game_init_sdl()) {
    exit_status = EXIT_SUCCESS;
  }
  game_free();

  return exit_status;
}
//test for failure

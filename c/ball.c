#include <stdio.h>
#include <SDL3/SDL.h>

#define WIDTH 900
#define HEIGHT 600
//window does not open in wayland compositor, well hyprland for me 
//imagine grid of pixels with 0,0 bing the top left and working our way 
//down. circle c is defined to be all points r distace away from center o at (ox, oy).
// If we assume the corodinates of this new set of points to be 0,0 t make math easier
// then formula can be
// def drawCircle(ox, oy, r):
// x = 0
// y = r 
// while x < y:
// y_mid = y+0.5 //midpoint betwixt  y and y +1
// if x*x + y_mid*y_mid > r*r:
// y += 1 //test if pixile is in the circle 
//placePixel(ox+x, oy+y)
// x+= 1
// repeat 8 times for coctant but this is inefficent and .5 is not an integer which is slower to multiply
// if a decison parameter p = x*x + y_mid*y_mid - r is used then we can ste if that is 
// less than or equal to zero
//rotation of 90 is [[0, -1],[1, 0]]
//rotation of 180 is [[-1, 0],[0, -1]]
//rotation of 270 is [[0, 1],[-1, 0]]
// reflection x axis is [[1, 0],[0, -1]]
// reflection y axis is [[-1, 0],[0, 1]]
// reflection y=x axis is [[0, 1],[1, 0]]
// because sdl coordinates star at (0,0) at top lef and Y increases as you go down while x increases to the right, (0, -y) in our relative coordiante system is 
//the best starting point for the first octant. then count each ocatnht rotating oucter clockwise
//thus the 8 sets of points can be defined as:
//1. algorithm
//2. reflect line 5 over x axis
//3. rotate (1) 90
//4. reflect line 7 over y axis
//5. rotate (1) 180
//6. reflect line 1 over x axis
//7. rotate (1) 270
//8. reflect line 3 over y axis
//all points will need to be translated back to sdl by the formulae: sdl_x = x+ox , sdl_y = y+oy
int main()
{
  printf("ball pit open\n");
  SDL_Init(SDL_INIT_VIDEO); //clearify
  SDL_CreateWindow("ball pit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  SDL_Delay(3000);

}

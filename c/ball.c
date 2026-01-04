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
int main()
{
  printf("ball pit open\n");
  SDL_Init(SDL_INIT_VIDEO); //clearify
  SDL_CreateWindow("ball pit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  SDL_Delay(3000);

}

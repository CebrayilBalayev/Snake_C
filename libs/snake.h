#ifndef SNAKE
#define SNAKE

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include  <windows.h>
#endif
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <unistd.h>
#include <time.h>

//changeable. For the better GUI use 16,32,64,128,256
#define size 32

#define SIZE 1040 //1024 + 2*margin => margin = 8
#define MARGIN 8
#define pixel_size (SIZE-(2*MARGIN))/size

enum direct{TOP,BOTTOM,LEFT,RIGHT};

typedef struct snake{
	int row;
	int column;
	struct snake *next;
}snake;

snake *newElem(int r,int c);
snake *addToHead(snake *head,snake *con);
int random0n(int n);

#endif

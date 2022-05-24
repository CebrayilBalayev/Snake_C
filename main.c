#include "sdlrender.h"
#include "move.h"
#include "snake.h"

int main(){
	srand(time(NULL)); 
	int direction = 0;
	int **plane = allocatedMatrix();

	snake *snake = newElem(size/2,size/2);
	snake = addToHead(snake,newElem(size/2,size/2));

	int appleRow = random0n(size/2);
	int appleCol = random0n(size/2);
	plane[appleRow][appleCol] = 2;

	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		fprintf(stderr,"Problem can not init SDL2 \n");
		return 0;
	}

	SDL_Window* window = SDL_CreateWindow("SNAKE",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SIZE , SIZE , SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	assert(renderer != NULL);

	drawmatrix(renderer,plane);
	SDL_RenderPresent(renderer);

	bool quit = false;
	bool play = true;
	while (!quit){
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event)){
			if(event.type == SDL_KEYDOWN){
     		if(event.key.keysym.sym == SDLK_RIGHT) direction = RIGHT;  			
     		else if(event.key.keysym.sym == SDLK_LEFT)direction = LEFT;
     		else if(event.key.keysym.sym == SDLK_UP) direction = TOP;
     		else if(event.key.keysym.sym == SDLK_DOWN) direction = BOTTOM;
			}
			if(event.type == SDL_MOUSEBUTTONDOWN)
				if(event.button.button == SDL_BUTTON_LEFT)
					play = !play;
			if(event.type == SDL_QUIT){quit = true;break;}
		}

		if(play){
			plane = moveto(plane,&snake,direction);
	    	drawmatrix(renderer,plane);
			SDL_RenderPresent(renderer);
			SDL_Delay(80);

			if(appleCol == snake->column && appleRow == snake->row){
				snake = addToHead(snake,newElem(appleRow,appleCol));
				while(1){
					appleRow = random0n(size);
					appleCol = random0n(size);
					if(plane[appleRow][appleCol] == 0)break;
				}
				plane[appleRow][appleCol] = 2;
			}
		}

	}
	SDL_Quit();
	return 0;
}
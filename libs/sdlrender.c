#include "sdlrender.h"

void addcolor(SDL_Renderer* renderer,SDL_Rect rect,int row,int column){
	rect.x=column*pixel_size + MARGIN;
	rect.y=row*pixel_size + MARGIN;
	SDL_RenderFillRect(renderer, &rect);
}

void drawmatrix(SDL_Renderer* renderer,int **matrix){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	SDL_Rect rect = {.w = pixel_size,.h = pixel_size};

	SDL_SetRenderDrawColor(renderer, 255,255,0,255);
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
			if(matrix[i][j])
				if(matrix[i][j] == 1) SDL_SetRenderDrawColor(renderer, 255,255,0,255);	
				else SDL_SetRenderDrawColor(renderer, 255,0,0,255);
			else SDL_SetRenderDrawColor(renderer, 0,0,0,255);
				
			addcolor(renderer,rect,i,j);
		}
}

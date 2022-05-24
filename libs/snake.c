#include "snake.h"

snake *newElem(int r,int c){
	snake *s = malloc(sizeof(snake));
	s->row = r;s->column = c;
	s->next = NULL;
	return s;
}

snake *addToHead(snake *head,snake *con){
	snake *h = con;
	h->next = head;
	return h;
}

int random0n(int n){
	return random()%n;
}
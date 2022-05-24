#include "move.h"

int **allocatedMatrix(){
	int **matrix;
	matrix=(int **)malloc(size*sizeof(int *));
	for(int i=0;i<size;i++)
		matrix[i]=(int *)malloc(size*sizeof(int));

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;

	return matrix;
}

int **moveto(int **matrix,snake *(*head),int direction){
	int r = (*head)->row;int c = (*head)->column;
	int **plane = matrix;

	snake *h = *head;
	while(h->next->next!=NULL) h = h->next;
	plane[h->next->row][h->next->column] = 0;

	h->next = NULL;

	if(direction == TOP) *head = addToHead(*head,newElem((r+size-1)%size,c));
	else if(direction == BOTTOM) *head = addToHead(*head,newElem((r+size+1)%size,c));
	else if(direction == LEFT) *head = addToHead(*head,newElem(r,(c+size-1)%size));
	else if(direction == RIGHT) *head = addToHead(*head,newElem(r,(c+size+1)%size));

	h = *head;
	while(h!=NULL){
		plane[h->row][h->column] = 1;
		h = h->next;
	}
	return plane;
}

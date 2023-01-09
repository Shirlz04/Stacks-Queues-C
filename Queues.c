#include <Stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue{
	char letter;
	struct queue *next;
	
};

struct queue *enqueue(struct queue **first, struct queue *end, char c){
	struct queue *temp = end;
	struct queue *new = NULL;
	new = malloc(sizeof(struct queue));
	new->letter = c;
	new->next = NULL;
	if (end == NULL){
		end = new;
		*first = new;
	}
	else {
		temp->next = new;
		end = new;
	}
	return end;
}

struct queue *dequeue(struct queue *first){
	struct queue *temp = first;
	first = first->next;
	temp->next = NULL;
	return first;
}

void printQueue(struct queue *first){
	struct queue *temp = first;
	while(temp != NULL){
		printf("%c ",temp->letter);
		temp = temp->next;
	}
}

int main(){
	struct queue *first = NULL;
	struct queue *end = NULL;
	end = enqueue(&first, end, 'o');
	end = enqueue(&first, end, 'k');
	end = enqueue(&first, end, 'l');
	printQueue(first);
	printf("\n");
	first = dequeue(first);
	printQueue(first);


}
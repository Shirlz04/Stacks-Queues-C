#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
	char letter;
	struct stack *next;
};

struct stack *push(struct stack *first, char c){
	struct stack *new;
	new = malloc(sizeof(struct stack));
	new->letter = c;
	new->next = NULL;
	if (first == NULL)
		first = new;
	else {
		new->next = first;
		first = new;
	}
	return first;
}

struct stack *pop(struct stack *first){
	struct stack *temp; 
	temp = first;
	first = first->next;
	temp->next = NULL;
	return first;
}

void printStack(struct stack *first){
	printf("\n");
	struct stack *temp = first;
	while(temp != NULL){
		printf("%c ",temp->letter);
		temp = temp->next;
	}
}

// cd desktop\c programming gcc -o stacks stacks.c

int main() {
	struct stack *first = NULL;
	first = push(first, '9');
	first = push(first, '8');
	printStack(first);
	first = pop(first);
	printStack(first);
}
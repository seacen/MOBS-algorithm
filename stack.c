#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack*
create(int size) {
	Stack *s;
	s = (Stack*)malloc(sizeof(*s));
	s->nextFree=0;
	
	return s;
}

int
push(Stack *s, void *x) {
	if (s->nextFree==MAX_STACK_SIZE) {
		return STACK_PUSH_FAIL;
	}
	s->data[s->nextFree]=malloc(sizeof(int));
	*(int*)(s->data[s->nextFree])=*(int*)x;
	s->nextFree+=1;
	return STACK_OK;
}

void*
pop(Stack *s) {
	s->nextFree-=1;
	return s->data[s->nextFree];
}

int
isEmpty(Stack *s) {
	if (s->nextFree==0) {
		return 1;
	}
	return 0;
}

void*
peek(Stack *s) {
	return s->data[s->nextFree-1];
}

void  freeStack(Stack *s) {
	free(s);
}

void printInt(void *x) {
	printf("%5d",*(int*)x);
}

void printLong(void *x) {
	printf("%5ld",*(long*)x);
}
/*purely designed for printing the "track" stack, since it is the only place
to be able to use this function*/
void printStack(Stack *s, void (*printFn)(void *)) {
	int i;
	printf("#NumQuestions            Responses\n\n");
/*iterate 2 items at a time*/
	for (i=0;i<(s->nextFree);i+=2) {
		printf("#");
		printFn(s->data[i]);
		printf("                    ");
		printFn(s->data[i+1]);
		printf("\n");
	}
	printf("#---------------------------------\n\n");
}
	



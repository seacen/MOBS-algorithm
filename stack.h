/* 
 COMP20007 Design of Algorithms 

 Generic stack data structure with
    create()
    push(x)
    pop()
    isEmpty()
    peek()
    freeStack()

 Author: Andrew Turpin (aturpin@unimelb.edu.au)
 Date: March 2014
*/

#define STACK_OK 0          // returned if push() succeeds
#define STACK_PUSH_FAIL 1   // returned if push() fails

#define MAX_STACK_SIZE 1024

typedef struct {
    void *data[MAX_STACK_SIZE];    // an array of void * pointers
    int nextFree;                  // index of next free slot (top of stack)
} Stack;

Stack *create(int size);        // return a new stack of size size
int   push(Stack *s, void *x);  // push return a new stack, return STACK_OK on success
void  *pop(Stack *s);           // pop top element of stack
int   isEmpty(Stack *s);        // 1 if stack is empty, 0 otherwise
void  *peek(Stack *s);          // return element on top of stack (no pop)
void  freeStack(Stack *s);      // free memory allocated in create()

void printStack(Stack *s, void (*printFn)(void *));
void printInt(void *x);
void printLong(void *x);

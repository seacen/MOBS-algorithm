#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "binarySearch.h"
#include <assert.h>
#include "oracle.h"
#include "mobs.h"
#include <math.h>

#define LESS           0       /* represents a less response in oracle*/
#define GREATER        1       /* represents a less response in oracle*/
#define EMPTY          2       /* no response is existed yet*/

void
mobs(long U, long L, long t, float p, long *answer, 
	                                     int *numQuestions) {
	Stack *Su, *Sl, *Intrack;
	int u,l,m=0,intT,ans,rev=0,prev=EMPTY,curr=EMPTY;
	Su=create(MAX_STACK_SIZE);
	Sl=create(MAX_STACK_SIZE);
/* a further stack for tracking numquestions and responses */
	Intrack=create(MAX_STACK_SIZE);
	u=(int)U;
	l=(int)L;
	intT=(int)t;
	assert(!push(Su,&u));
	assert(!push(Sl,&l));
/*if both conditions of 1 and 2 reached or 3 is reached, the loop terminates*/
	while ((((u-l)>MOBS_TOLERANCE*((int)(U-L))) || (rev<4))
		                && (*numQuestions<10*log(U+L-1)/log(2))) {
		m=(u+l)/2;
		*numQuestions+=1;
		ans=oracle(m,intT,p);
		assert(!push(Intrack,numQuestions));
		assert(!push(Intrack,&ans));
		if (ans==1) {
			l=m+1;
			assert(!push(Sl,&l));
/*two variables to store the previous and current responses, use for counting
reversals and stack checks*/
			prev=curr;
			curr=GREATER;
		}
/*Both cases of ans==0 and ans==-1 will follow this arrangement*/
		else {
			u=m-1;
			assert(!push(Su,&u));
			prev=curr;
			curr=LESS;
		}
		if ((prev!=curr) && (prev!=EMPTY)) {
			rev++;
		}
/*a stack check that follows the instruction on specs*/
		if ((prev==curr) && (prev==LESS)) {
			if (*(int*)(Sl->data[Sl->nextFree-1])>intT) {
				pop(Sl);
			}
/*if the whole stack is empty, push the original limit to stack, same below*/
			if (isEmpty(Sl)) {
				l=(int)L;
				assert(!push(Sl,&l));
			}
		}
		
		if ((prev==curr) && (prev==GREATER)) {
			if (*(int*)(Su->data[Su->nextFree-1])<intT) {
				pop(Su);
			}
			if (isEmpty(Su)) {
				u=(int)U;
				assert(!push(Su,&u));
			}
		}
		l=*(int*)Sl->data[Sl->nextFree-1];
		u=*(int*)Su->data[Su->nextFree-1];
	}
	*answer=(long)m;
	printStack(Intrack,printInt);
}

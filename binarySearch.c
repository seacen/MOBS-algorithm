#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "binarySearch.h"
#include <assert.h>
#include "oracle.h"

void
binarySearch(long U,long L,long t,float p,long *answer,
	                                    int *numQuestions) {
	Stack *Su, *Sl,*Intrack;
	int u,l,m,intT,ans;
	Su=create(MAX_STACK_SIZE);
	Sl=create(MAX_STACK_SIZE);
	Intrack=create(MAX_STACK_SIZE);
/* a further stack for tracking numquestions and responses */
	u=(int)U;
	l=(int)L;
	intT=(int)t;
	assert(!push(Su,&u));
	assert(!push(Sl,&l));
	while (l<=u) {
		m=(u+l)/2;
		*numQuestions+=1;
		ans=oracle(m,intT,p);
		assert(!push(Intrack,numQuestions));
		assert(!push(Intrack,&ans));
/*a simple binary search which cut the range in halve each time to look for t*/
		if (ans==0) {
			*answer=(long)m;
			l=u+1;
			assert(!push(Sl,&l));		
		}
		else if (ans==1) {
			*answer=(long)m;
			l=m+1;
			assert(!push(Sl,&l));
		}
		else {
			*answer=(long)m;
			u=m-1;
			assert(!push(Su,&u));
		}
	}
	printStack(Intrack,printInt);
}

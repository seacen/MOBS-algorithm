/* 
 COMP20007 Design of Algorithms 

 Simple binary search in integers, recording limits on stacks, and a test harness.

 Author: Andrew Turpin (aturpin@unimelb.edu.au)
 Date: March 2014

 Usage: binarySearch Upper_limit Lower_limit prob_of_error

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "stack.h"
#include "oracle.h"
#include "binarySearch.h"
#include "mobs.h"

/*
** Print usage message
*/
void
usage(char *exeName) { 
    fprintf(stderr,"Usage: %s m L U t p n\n",exeName);
    fprintf(stderr,"       where\n");
    fprintf(stderr,"          m - M for MOBS, B for Binary Search, Z for both\n");
    fprintf(stderr,"          L - lower limit (integer)\n");
    fprintf(stderr,"          U - upper limit (integer)\n");
    fprintf(stderr,"          t - target of search (integer)\n");
    fprintf(stderr,"          p - probability of oracle giving incorrect response (float)\n");
    fprintf(stderr,"          n - number of repeat runs (int)\n");
}

/*
** Read command line params, call search
*/
int 
main(int argc, char *argv[]) {
    assert(sizeof(void *) == sizeof(long));

    if (argc != 7) {
        usage(argv[0]);
        return(-1);
    }

    srand(time(NULL));  // choose current time as random seed

    char method;
    long U, L, target;
    int n;
    float p;
    sscanf(argv[1], "%c", &method);
    sscanf(argv[2], "%ld", &L);
    sscanf(argv[3], "%ld", &U);
    sscanf(argv[4], "%ld", &target);
    sscanf(argv[5], "%f", &p);
    sscanf(argv[6], "%d", &n);
    
    long answer;
    int numQuestions;

    printf("# Method L U Target p Answer Num_questions\n");
    for(int i = 0 ; i < n ; i++) {
        numQuestions = 0;
        if (method == 'M' || method == 'm' || method == 'Z' || method == 'z') {
            mobs(U, L, target, p, &answer, &numQuestions);
            printf("M %ld %ld %ld %f: %3ld %3d\n", L,U,target, p, answer, numQuestions);
        }
        numQuestions = 0;
        if (method == 'B' || method == 'b' || method == 'Z' || method == 'z') {
            binarySearch(U, L, target, p, &answer, &numQuestions);
            printf("B %ld %ld %ld %f: %3ld %3d\n", L,U,target, p, answer, numQuestions);
        }
    }

    return 0;
}

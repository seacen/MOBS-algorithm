/* 
 COMP20007 Design of Algorithms 

 Simple binary search in integers, recording limits on stacks, and a test harness.

 Author: Andrew Turpin (aturpin@unimelb.edu.au)
 Date: March 2014

*/

#define MOBS_TOLERANCE 0.01    // don't stop until stacks are <= this*(U-L) far apart

void mobs(long U, long L, long t, float p, long *answer, int *numQuestions);

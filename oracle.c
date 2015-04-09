/* 
 COMP20007 Design of Algorithms 

 A simple oracle on integers that lies with probability p

 Author: Andrew Turpin (aturpin@unimelb.edu.au)
 Date: March 2014

*/

#include <stdlib.h>

/*
** Inputs:
**    stimulus - the probe value
**    target   - the value that is the target of the search
**    p        - probability of lying
** Outputs:
**   if (p == 0)
**       -1 if target < stimulus or target == stimulus (50%)
**       +1 if target > stimulus or target == stimulus (50%)
**   if (p > 0) then the results might flip.
**   I have chosen not to lie about the real answer (0 not changed)
*/
int 
oracle(long stimulus, long target, float p) {
    int answer = 0;

    if (target < stimulus)
        answer = -1;

    if (target > stimulus)
        answer = +1;

    if (target == stimulus)
        answer = 0;

    if (answer != 0 && (float)rand() / (float)RAND_MAX < p) {
        if (answer == -1)
            answer = +1;
        else if (answer == +1)
            answer = -1;
    }

    return answer;
}

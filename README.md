# MOBS-algorithm
design of algorithm ass1

Usually we assume that the comparison operator (sometimes called an oracle) in our sorting and searching
algorithms functions correctly. That is, when we ask if (3 > 2), we always get the answer +1. But what if the
oracle is faulty (for example, a human)?
In their paper \A rapid technique to asses the resting state of the eyes and other threshold phenomena: The Modied
Binary Search (MOBS)" [Behaviour Research Methods, Instruments & Computers, 1988 20(2) pages 137-141], Tyrrel
and Owens described a simple heuristic to add to binary search that allows for comparison errors. The idea is that
you store the upper and lower limits of the binary search on two stacks, and if two answers in a row are identical,
you check the appropriate limit to see if it is still correct. They also altered the termination criteria of the loop.

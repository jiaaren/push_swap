Data structure used
- Deques (doubly ended queues) in the form of doubly linked lists. Included functions for creation, adding (back & front), deletion/popping (back & front), counting sizes.
- Included a stack (single deque) & stacks (double deque) typedef. Double deques are used to mimic environment of subject question.
- To complement the 11 operations allowed, added 11 functions to mimic what the actual operations do to the stacks, (i.e. sa, sb, ss, pa, pb, ra, rb…).

Sorting algorithms
- Quadratic sorting algorithms are a no go - i..e bubble/ selection/ insertion due to n2 time complexity.
- Second best sorting algorithms are linearithmic/comparison sorts, e.g. merge or quick sorts.
- There are O(n) sorting algorithms, e.g. radix sort. However, due to nature of a stack data structure, it is not possible to achieve O(n), as movements within/between stacks are merely rotation, or popping.


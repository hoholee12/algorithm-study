# QuickSort is faster than MergeSort
## why?
### 1. it does not copy the whole array to sort and put it back.
nono, QuickSort on the otherhand swaps each element until satisfied.
### 2. cache misses
in MergeSort, it divides subproblems and conquers up to a single solution. comparison happens from left to right and then proceeds to the next subproblems with different memory area, before going up one layer for bigger subproblems.

that means its always looking at different areas of the memory. nono not good very bad situation for caching.

meanwhile, QuickSort sorts before dividing into subproblems. while memory is partially sorted, you dive into subproblems. they at least share the same memory area in a 1/4 chance.

so you'll be sorting with more cache time, and cache misses are much less likely to happen than MergeSort.

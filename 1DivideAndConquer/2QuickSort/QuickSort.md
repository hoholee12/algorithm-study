# QuickSort is faster than MergeSort
## why?
### 1. proper pivot placement can lead to less than n times per conquer.
as long as it leads to divided subproblems size less than 3/4.

in comparison, merge sort always does n times comparison in conquer.
### 2. cache misses
in MergeSort, it divides subproblems and conquers up to a single solution. comparison happens from left to right and then the next subproblems.

that means its always looking at different areas of the memory. nono not good very bad situation for caching.

meanwhile, QuickSort sorts before dividing into subproblems. while memory is cached, you dive into subproblems. they at least share the same memory area in a 1/4 chance.

so cache misses are much less likely to happen frequently than MergeSort.

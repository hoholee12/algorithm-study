# ScoopSort vs QuickSort

*test results:*

### size = 10000000, rand() short int range:

*quicksort: took 12 seconds*

*above: 1 loop, took 0 seconds*

### size = 10000000, rand() int range:

*quicksort: took 8 seconds*

*above: 108 loops, took 21 seconds*

its good enough for small values since its basically a counting sort, but for big values not so much.

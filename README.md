# Median
Median filtering is an efficient mean to remove impulse noise from signal. As a filter is a non linear process and algorithm complexity is the same as sorting Used as a flter for iamges it is not separable and coputation can become prohibitive with large kernel. 

Within this scope this is a very fast and simple algorithm to find median value in a vector of integers in RANGE. The is no need for sort or comparison, it is based on building an histogram of values and then integrate histogram up to n/2.
This approach was proved to be much faster than and other meth based on sort: quicksort, radixsort, quickselect, binsort,median-of-median, etc.

This algorithm is simple and fast but sequential and not so easy to parallelelize. due to contention when building the histogram. A CUDA version is currently under developpement.

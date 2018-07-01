# median
In the scope of staking astronomical pics of deep sky, median is a basic process to eliminate noise and increase signal/noise ratio.This is a very CPU intensive operation as the images are large anWed stack can be fairly large. Search for median value in a vector usually useally goes through a sort then select n/2 element. Images pics are integer values in [0-RANGE]. Sort operation will slow down when vector size increase.

This is a very fast and simple algorithm to find median value in a vector of integers in RANGE. The is no need for sort or comparison, it is based on building an histogram of values and then integrate histogram up to n/2.
This approach was proved to be much faster than and other meth based on sort: quicksort, radixsort, quickselect, binsort,median-of-median, etc.
This algorithm is simple and fast but sequential and not so easy to parallelelize. due to contention when building the histogram. 
However a CUDA version is in developpement.

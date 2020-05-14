/*
 * Three Way Partition Quick median take an array of n float 
 * and returns the median value. It combines the three way partition 
 * algorithm or "Dutch Flag" from Edsger Dijkstra and the Quick Select 
 * from Tony Hoare. Strategy is divide and Conquer.
 * The array is split iteratively in 3 parts: < = > of pivot 
 * Outperforms QuickSelect algorithm for arrays with duplicates or pre sorted.
 * Warning: in place value shuffling
 * Written by Emmanuel Brandt 2019-04
 * @param a array of float
 * @param n array size
 * @return median as float
 */
 
/* 
** Quickmedian takes an array a of n float and return the median value. 
** Use quicksort on half of the array, iterative version.
**/
float quickmedian1(float *a, int n) 
{	
	int i;
	int k = n / 2;		// size to sort
	int pindex;			// pivot index
	int left = 0; 		// left index
	int right = n - 1; 	// right index
	register float pivot, tmp;

	while (left < right) { //we stop when our indicies have crossed
		pindex = (left + right) / 2; // pivot selection, this can be whatever
		pivot = a[pindex];
		a[pindex] = a[right];
		a[right] = pivot; // SWAP(pivot,right)

		for (i = pindex = left; i < right; i++) {
			if (a[i] < pivot) { // SWAP
				tmp = a[pindex];
				a[pindex] = a[i];
				a[i] = tmp;
				pindex++;
			}
		}
		a[right] = a[pindex];
		a[pindex] = pivot; // SWAP

		if (pindex < k)
			left = pindex + 1;
		else // pindex >= k
			right = pindex;
	}
	return a[k];
}


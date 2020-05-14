// EB quickselect returns the k-th smallest item in array x of length len
#include <stdio.h>

#define SWAP(i, j) { tmp = a[i]; a[i] = a[j]; a[j] = tmp; }

unsigned short medianQuickSelect(unsigned short *a, int n, int k) {
	int i, j, left = 0, right = n - 1;
	unsigned short pivot, tmp;
	
	while (left < right) {
		pivot = a[k]; printf("\nleft=%d pivot=%u right=%d", left, pivot, right);
		SWAP(right, k); printf("\nSWAP(right=%d, k=%d)", right, k);
		printArray(a, n);
		
		for (i = j = left; i < right; i++) {
			if (a[i] < pivot) {
            	SWAP(i, j); 
            	printf("\na[%d]=%u < %d SWAP(i=%d, j=%d)", i, a[i], pivot, i, j);   	
            	j++;
         	}
         	printArray(a, n);
         	printf("\ni=%d j=%d", i, j);
		}	 
		SWAP(right, j); 
		printf("\nSWAP(right=%d, j=%d) left=%d", right, j, left);
		printArray(a, n);
 
		if (j == k) break;
		if (j < k) left = j + 1;
		else right = j - 1;
   }
   return a[k];
}

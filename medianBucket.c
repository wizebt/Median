// Author E. BRANDT 2018-06
// Fast method to find median from an array of integers without sort
// Build the histogram of integer values of a in b
// Find median by integration of up to n/2
// Complexity is O(n)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 4096 // range of integer (pix) values

void init(int *a, int n) {
	srand(time(NULL));
	for(int i=0; i<n; i++)
		a[i] = 20 + rand() % 10;
}

void printArray(int *a, int n) {
	printf("\n");
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int medianBucket(int *b, int *a, int n) {
	int i, s;
	
	for(i=0; i<n; i++) b[a[i]]++;
	
	for(i=0, s=0; s < n/2; i++) s += b[i];
	
	return i-1;
}

int main() {
	printf("\nEnter array size: ");
	int n=11;
	scanf("%d", &n);
	
	int *a, *b, median, i;

	a = malloc(n*sizeof(int));
	b = malloc(RANGE*sizeof(int));
	init(a, n);
	//printArray(a, n);
	
	time_t t = clock();
	median = medianBucket(b, a, n);
	printf("\nBucket Sort median %d duration=%f sec", median,
			(double)(clock() - t) / CLOCKS_PER_SEC);
	//printArray(b, RANGE);
	
	printf("\n");
	free(a); free(b);
	return 0;
}

/*
** Copyright (C) 2020 Emmanuel Brandt <wizebt@gmail.com>
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// quick sort, recursive implementation
void quicksort(float *a, int n) 
{
	if (n < 2) return;
	float tmp, pivot = a[n/2];
	float *left = a, *right = a + n - 1;
	
	while(left <= right) {
		// we need to check the condition (l <= r) 
		// every time we change the value of l or r
		if (*left < pivot) {
			left++;
			continue;
		}
		
		if (*right > pivot) {
			right--;
			continue; 
		}
		
		tmp = *left;
		*left++ = *right;
		*right-- = tmp;
	}
	
	quicksort(a, right - a + 1);
	quicksort(left, a + n - left);
}

/* 
** Quick select returns the k-th smallest item in array x of length n. 
** Use quicksort on half of the array, iterative version.
**/
#define swap(i, j) { tmp = a[i]; a[i] = a[j]; a[j] = tmp; }
float quickselect(float *a, int n, int k) {
	int i, j, left = 0, right = n - 1;
	register float pivot, tmp;
	
	while (left < right) {
		pivot = a[right];
		
		for (i = j = left; i < right; i++) {
			if (a[i] < pivot) {
            	swap(i, j); 	
            	j++;
         	}
		}	 
		swap(right, j); 

		if (j == k) break;
		if (j < k) left = j + 1;
		else right = j - 1;
   }
   return a[k];
}

float quickmedian(float *a, int n) {
	int i, j, left = 0, right = n - 1;
	int k = n / 2;
	register float pivot, tmp;
	
	while (left < right) {
		pivot = a[right];
		
		for (i = j = left; i < right; i++) {
			if (a[i] < pivot) {
            	swap(i, j); 	
            	j++;
         	}
		}	 
		swap(right, j); 

		if (j == k) break;
		if (j < k) 
			left = j + 1;
		else 
			right = j - 1;
   }
   return a[k];
}

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

float twpqm(float *a, int n) 
{
	int left, l, j, right, r, k;
	float pivot, tmp;
	left = l = j = 0;
	right = r = n-1;
	k = n/2; // pivot index
	pivot = a[k]; // pivot value
	
	while (left <= right) {
		while (j <= r) { // 3 way partition < = >
			if (a[j] < pivot) {
				swap(j, l);
				//tmp = a[j]; a[j] = a[l]; a[l] = tmp; // swap a[j] a[l]
				l += 1;
				j += 1;
			} else if (a[j] > pivot) {
				swap(j, r);
				//tmp = a[j]; a[j] = a[r]; a[r] = tmp; // swap a[j] a[r]
				r -= 1;
			} else 
				j += 1;
		}

		if (k > r) {
			left = l = j = r+1;
			r = right;
		} else if (k < l) {
			r = right = l-1;
			l = j = left;	
		} else {
				return pivot;
		}
		pivot = a[(l+r)/2];
	}
}
#undef swap

/*
** qm9(x) -> median of 9 elements
** Mahmoudi's algorithm, triple sorter median algorithm, 19 comparison.
*/
#define swap(i,j) { if (x[i] > x[j]) {t=x[i]; x[i]=x[j]; x[j]=t;} }
float qm9(float *x) {
    register float t;
    //float x[9];
    //for (int i = 0; i < 9; i++) x[i] = a[i];

    swap(0,1); // swap(a,b)
    swap(1,2); // swap(b,c)
    swap(0,1); // swap(a,b)

    swap(3,4); // swap(f,g)
    swap(5,6); // swap(g,h)
    swap(3,4); // swap(f,g)

    swap(6,7); // swap(k,l)
    swap(7,8); // swap(l,m)
    swap(6,7); // swap(k,l)

    if (x[0] > x[3]) x[3]=x[0]; // max(a,f)
    if (x[3] > x[6]) x[6]=x[3]; // max(f,k)

    swap(1,4); //swap(b,g)
    if (x[7] < x[4]) x[4] = x[7]; //min(g,l)
    if (x[1] > x[4]) x[4] = x[1]; // max(b,g)

    if (x[8] < x[5]) x[5] = x[8]; // min(h,m)
    if (x[5] < x[2]) x[2] = x[5]; // min(c,h)

    swap(6,4); // swap(k,g)
    if (x[2] < x[4]) x[4] = x[2]; // min(g,c)
    if (x[6] > x[4]) x[4] = x[6]; // max(k,g)

    return x[4];
}
#undef swap

// Driver program to test the above functions

void printArray(float *a, int n) {
	printf("\n");
	for(int i = 0; i < n; i++) printf("%f ", a[i]);
	printf("\n");
}

void init(float *a, int n) {
	srand(clock());
	for(int i=0; i<n; i++) a[i] = (float) rand() / (float) RAND_MAX;
}

int main() {
	int i, n;
	double d;
	time_t t;
	
	printf("\nEnter odd array size: ");
	scanf("%d", &n);
	
	float median, *a = malloc(n*sizeof(float));
	
	init(a, n);
	t = clock();
	median = quickselect(a, n, n/2);
	d = (double) (1000 * (clock() - t) / CLOCKS_PER_SEC);
	printf("\nquickselect\tmedian=%f duration=%0.f ms", median, d);

	init(a, n);
	t = clock();
	median = quickmedian(a, n);
	d = (double) (1000 * (clock() - t) / CLOCKS_PER_SEC);
	printf("\nquickmedian\tmedian=%f duration=%0.f ms", median, d);

	//init(a, n);
	t = clock();
	median = twpqm(a, n);
	d = (double) (1000 * (clock() - t) / CLOCKS_PER_SEC);
	printf("\n3-way partition\tmedian=%f duration=%0.f ms", median, d);

	t = clock();
	quicksort(a, n);
	median = a[n/2];
	d = (double) (1000 * (clock() - t) / CLOCKS_PER_SEC);
	printf("\nquicksort\tmedian=%f duration=%0.f ms", median, d);

	if (n == 9) {
		init(a, n);
		t = clock();
		median = qm9(a);
		d = (double) (1000000 * (clock() - t) / CLOCKS_PER_SEC);
		printf("\nmedian9\t\tmedian=%f duration=%0.f us", median, d);
	}

	printf("\n");
	free(a);
	return 0;
}

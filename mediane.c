// Author E. BRANDT 2018
// Comparision median search quicksort, quick select

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned short WORD;
#define RANGE 11

void printArray(WORD *a, int n) {
	printf("\n");
	for(int i=0; i<n; i++) 
		printf("%hu ", a[i]);
	printf("\n");
}

void init(WORD *a, int n) {
	srand(1);
	for(int i=0; i<n; i++) 
		a[i] = rand() % RAND_MAX;
}

#define SWAP(i, j) { tmp = a[i]; a[i] = a[j]; a[j] = tmp; }

// Quick select returns the k-th smallest item in array x of length len
// iterative version
WORD quickselect(WORD *a, int n, int k) {
	int i, j, left = 0, right = n - 1;
	WORD pivot, tmp;
	
	while (left < right) {
		pivot = a[right];
		
		for (i = j = left; i < right; i++) {
			if (a[i] < pivot) {
            	SWAP(i, j); 	
            	j++;
         	}
		}	 
		SWAP(right, j); 

		if (j == k) break;
		if (j < k) left = j + 1;
		else right = j - 1;
   }
   return a[k];
}

// quick sort
void quicksort(WORD *a, int n) {
	if (n < 2) return;
	WORD pivot = a[n/2], *left = a, *right = a + n - 1, tmp;
	
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

/**
 * In-place quick sort of array of WORD a of size n
 * @param a array to sort
 * @param n size of the array
 */
void quicksort_s(WORD *a, int n) {
	if (n < 2) return;
	WORD p = a[n / 2];
	WORD *l = a;
	WORD *r = a + n - 1;
	WORD t;
	while (l <= r) {
		if (*l < p) {
			l++;
			continue;
		}
		if (*r > p) {
			r--;
			continue; // we need to check the condition (l <= r) 
						// every time we change the value of l or r
		}
		t = *l;
		*l++ = *r;
		*r-- = t;
	}
	quicksort_s(a, r - a + 1);
	quicksort_s(l, a + n - l);
}

// Test quick select non recursive 
WORD quickSelectNR(WORD *a, int k, int n) {
	//if (n < 2) return;
	WORD pivot = a[0], tmp, *left = a, *right = a + n - 1;
	
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
			printArray(a, n);
		}
	/*
		if ((*left-a) == k) return a[k];
		else if ((*left-a) < k) *left++;
		else *right--; */
		return *left;
}

/* 
	This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot 
*/
int partition (WORD *a, int low, int high)
{
    // pivot (Element to be placed at right position)
    WORD pivot = a[high], tmp;  
 
    int i = low - 1, j;  // Index of smaller element

    for (j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (a[j] <= pivot)
        {
            i++;    // increment index of smaller element
            SWAP(i, j); 
        }
    }
    SWAP(i + 1, high);
    return i + 1;
}

/* low: Starting index,  high: Ending index */
void QSP(WORD *a, int low, int high)
{
	int pi;
	
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now at right place */
        pi = partition(a, low, high);

        QSP(a, low, pi - 1);  // Before pi
        QSP(a, pi + 1, high); // After pi
    }
}

/* low: Starting index,  high: Ending index */
void QSP1(WORD *a, int low, int high)
{
	WORD pivot = a[high], tmp;  
	int i = low - 1, j, pi;
	
    if (low < high)
    {
        // pi is partitioning index, a[pi] is now at right place 
        for (j = low; j <= high - 1; j++)
    	{
        	// If current element is smaller than or equal to pivot
        	if (a[j] <= pivot)
        	{
            	i++;    // increment index of smaller element
            	SWAP(i, j); 
        	}
    	}
    	i++;
    	SWAP(i, high);
    	pi = i;

        QSP1(a, low, pi - 1);  // Before pi
        QSP1(a, pi + 1, high); // After pi
    }
}

// Buble sort half of the array to return median
WORD medianBBSort(WORD *a, int n) {
	WORD tmp;
	
	for (int i = 0 ; i <= n/2; i++) 
    	for (int j = 0 ; j < n - i - 1; j++) 
      		if (a[j] > a[j+1]) 
        		SWAP(j, j+1);

	return a[n/2];
}

WORD medianNoSort(WORD *a, int n) {
	int i, n2 = n/2;
	WORD min, max, inf, sup, cinf, csup, dinf, dsup, p, ceq;
	
	min = max = a[0]; // Pivot min and max initialized with first value
	ceq = cinf = csup = 0; // Counter(s) equal, less and over
	
	// Find for min, max and mean to initialize pivot
	unsigned int sum = a[0];
	for(i=1; i < n; i++) {
		//sum += a[i];
		if(a[i] > max) max = a[i];
		else if(a[i] < min) min = a[i];
	}
	
	//p = sum/n;
	p = (a[0] + a[1] + a[2]) / 3;
	//printf("\nMean=%d", p);
	dinf = p - min; 
	dsup = max - p;

	int iter =0; // Iteration counter
	while(iter < 99) {
		iter++;
		inf = sup = p;
		dinf = p - min;
		dsup = max - p;
		ceq = cinf = csup = 0;

		for(i=0; i < n; i++) {
			if(a[i] < p) {
				cinf++;
				if ((p - a[i]) < dinf) { 
					inf = a[i];
					dinf = p - a[i];
				}
			}
			else if(a[i] > p) {
				csup++;
				if((a[i] - p) < dsup) {
					sup = a[i];
					dsup = a[i] - p;
				}
			}
			else if(a[i] == p) ceq++;
		}
		/*printf("\n#%d inf=%d cinf=%d dinf=%d p=%d sup=%d csup=%d dsup=%d", 
				iter, inf, cinf, dinf, p, sup, csup, dsup); */
		if(cinf > n2) p = inf;
		else if(csup > n2) p = sup;
		else if(cinf == n2 || (cinf + ceq) >= n2) break; 
	 } 

	 printf("\nNo sort %d iterations", iter);
	 return p;
}

WORD medianBucket(WORD *a, int n) {
	WORD b[RANGE] = {0};
	int i, s, n2 = n/2;

	for(i=0; i < n; i++) b[a[i]]++;

	i = 0; s = b[0];
	while(s <= n2) {
		i++;
		s += b[i];
	}
	
	return i;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(WORD*)a - *(WORD*)b );
}

#define sw(i,j) if(a[i] > a[j]) SWAP(i,j)
void sort(WORD *a, int n) {
WORD tmp;
	if (n == 2) sw(0,1);
	if (n == 3) { sw(0,1); sw(1,2); sw(0,1); }
	if (n == 4) { sw(0,1); sw(2,3); sw(0,2); sw(1,3); sw(1,2); }
	if (n == 5) { sw(0,1); sw(2,3); sw(1,3); sw(2,4); sw(0,2); 
		sw(1,4); sw(1,2); sw(3,4); sw(2,3); }
	printArray(a, n);
	printf("\nn=%d", n);
}
#undef sw

// selects the median of medians in an array
WORD mom(WORD *a, int s, int e, int k){
    // if the partition length is less than or equal to 5
    // we can sort and find the kth element of it
    // this way we can find the median of n/5 partitions
    if(e-s+1 <= 5)
    {
        //sort(a+s, a+e);
        //return s+k-1;
        sort (a+s, e-s+1);
        printf("\nmedian5=%u", a[s+2]);
        return a[s+2];
    }
    
    // if array is bigger, we partition the array in subarrays of size 5
    // no. of partitions: n/5 = (e+1)/5 iterate through each partition and 
    // recursively calculate the median of all of them
    // and keep putting the medians in the starting of the array
    int i, left, right, median;
    WORD tmp;   
    for (i=0; i < (e+1)/5; i++){
        left = 5 * i;
        right = left + 4;
        if (right > e) right = e;
        median = mom(a, 5*i, 5*i+4, 3);
        SWAP(median, i);
    }
    
    // now we have array 
    // a[0] = median of 1st 5 sized partition
    // a[1] = median of 2nd 5 sized partition
    // and so on till n/5
    // to find out the median of these n/5 medians
    // we need to select the n/10th element of this set (i.e. middle of it)
    return mom(a, 0, (e+1)/5, (e+1)/10);
}

// Driver program to test the above methods
int main() {
	int i, n;
	time_t t;
	printf("\nEnter array size: ");
	scanf("%d", &n);
	
	WORD median, *a = (WORD *) malloc(n*sizeof(WORD));
	/*
	init(a, n);
	t = clock();
	median = medianBBSort(a, n);
	printf("\nBuble sort median %u duration=%f sec", median,
			(double)(clock() - t) / CLOCKS_PER_SEC); 	init(a, n);
	
	init(a, n);
	t = clock();
	median = medianBucket(a, n);
	printf("\nBucket sort\tmedian=%u duration=%f sec", median, 
			(double)(clock() - t) / CLOCKS_PER_SEC);
	
	init(a, n);
	t = clock();
	median = medianNoSort(a, n);
	printf("\nNo sort\t\tmedian=%u duration=%f sec", median, 
			(double)(clock() - t) / CLOCKS_PER_SEC);
	*/
	init(a, n);
	t = clock();
	quicksort_s(a, n);
	median = a[n/2];
	printf("\nquicksort_s \tmedian=%u duration=%f sec", median,
			(double)(clock() - t) / CLOCKS_PER_SEC);
	
	init(a, n);
	t = clock();
	quicksort(a, n);
	median = a[n/2];
	printf("\nquicksort\tmedian=%u duration=%f sec", median,
			(double)(clock() - t) / CLOCKS_PER_SEC);
			
	init(a, n);
	t = clock();
	qsort(a, n, sizeof(WORD), cmpfunc);
	median = a[n/2];
	printf("\nqsort stdlib\tmedian=%u duration=%f sec", median,
			(double)(clock() - t) / CLOCKS_PER_SEC);
			
	init(a, n);
	t = clock();
	median = quickselect(a, n, n/2);
	printf("\nQuick Select\tmedian=%u duration=%f sec", median,
			(double)(clock() - t) / CLOCKS_PER_SEC);
	/*
	init(a, n);
	printArray(a, n);
	t = clock();
	median = mom(a, 0, n-1, n/2);
	printf("\nmedian of medians\tmedian=%u duration=%f sec", median,
			(double)(clock() - t) / CLOCKS_PER_SEC);

	init(a, n);
	t = clock();
	sort(a, n);
	median = a[n/2];  
	printf("\nsort\tmedian=%u duration=%f sec", median,
			(double)(clock() - t) / CLOCKS_PER_SEC);
	*/
	printf("\n");
	free(a);
	return 0;
}

/*
** Copyright (C) 2020 Emmanuel Brandt <wizebt@gmail.com>
**/

/*
	 qm3(x) -> median of 3 elements

Input 3, delay 3, comparison 3.
*/
float qm3(float *x) {
	float a=x[0], b=x[1], c = x[2];
	register tmp;

    if (a > b) { tmp = a; a = b; b = tmp; };
    if (c < b) { b = c };
    
    return a < b ? b : a;
}

/* 
 * Insertion sort median of an array of WORD of size n
 * Simple and most efficient for array of size upto 50
 */
float insertion_sort_median(float *a, int n) 
{ 
	register int i, j;
	register float tmp;
	
	for (i = 1; i < n; ++i) {
		tmp = a[i];
		j = i;
		while (j > 0 && tmp < a[j - 1]) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = tmp;
	}
	return a[n/2];
}

/*
	qm4(x) -> median of 4 elements

Input 4, delay 3, comparisons 4.
*/
float qm4(float *x) {
	float a, b, c, d = x
	
	if (a > b) { a, b = b, a }; 
	if (c > d) { c, d = d, c };
	if d < b b = d end; if a > c c = a end
	
	return 0.5(b + c);
}

/*
	qm5(x) -> median of 5 elements

Input 5, delay 6, comparison 8.
*/
float qm5(float *x) {
    float a, b, c, d, e = x

    if b > c b, c = c, b end
    if d > e d, e = e, d end
    if b > d b, d = d, b end
    if a > c a, c = c,a end
    if c > e c = e end
    if a > d a, d = d, a end
    if a > b b = a end
    if c > d c = d end

    return b > c ? b : c
}

/*
	qm6(x) -> median of 6 elements

Input 6, delay 6, comparison 11.
*/
float qm6(float *x) {
    float a, b, c, d, e, f = x

    if a > b a, b = b, a end
    if c > d c, d = d, c end
    if e > f e, f = f, e end
    if a > c a, c = c, a end
    if d > f d, f = f, d end
    if b > e b, e = e, b end
    if a > b b = a end
    if c > d c, d = d, c end
    if e > f e = f end
    if b > c c = b end
    if d > e d = e end

    return 0.5 * (c + d)
}

/*
	qm7(x) -> median of 7 elements

Input 7, delay , comparison .
*/
float qm7(float *x) {
    float a, b, c, d, e, f, g = x

    if b > c b, c = c, b end
    if d > e d, e = e, d end
    if f > g f, g = g, f end
    if a > c a, c = c, a end
    if e > g e, g = g, e end
    if d > f d, f = f, d end
    if c > g c = g end
    if b > f b, f = f, b end
    if a > e a, e = e, a end
    if c > f c = f end
    if a > d d = a end
    if c > e c, e = e, c end
    if b > d d = b end

    return c > d ? c : d
}

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
 * @return median as double
 */
 # define swap(i,j) { tmp = a[j]; a[j] = a[l]; a[l] = tmp; }
float twpqs(float *a, int n) {
	int left, l, j, right, r;
	register float pivot, tmp;
	
	left = l = j = 0;
	right = r = n-1;
	int k = n/2; 	// pivot index
	pivot = a[k]; 	// Initial pivot value
	
	while (left <= right) {
		while (j <= r) { // 3 way partition < = >
			if (a[j] < pivot) {
				swap(j, l);
				l += 1;
				j += 1;
			} else if (a[j] > pivot) {
				swap(j, r);
				r -= 1;
			} else j += 1;
		}

		if (k > r) {
			left = l = j = r+1;
			r = right;
		} else if (k < l) {
			r = right = l-1;
			l = j = left;
		} else return pivot;
	}
}
#undef swap

/*
	qm9(x) -> median of 9 elements

Mahmoudi's triple sorter median algorithm, 19 comparison.
in place sort
*/
#define swap(i,j) { if (x[i] > x[j]) {t=x[i]; x[i]=a[j]; x[j]=t;} }
float qm9(float *x) {
    register float t;

    swap(0,1); // swap(a,b)
    swap(1,2); // swap(b,c)
    swap(0,1); // swap(a,b)

    swap(3,4); // swap(f,g)
    swap(5,6); // swap(g,h)
    iswap(3,4); // swap(f,g)

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

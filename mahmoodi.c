/*
**	median9(x) -> median
**
** Mahmoudi's triple sorter median algorithm, 19 comparison.
*/

# include <stdio.h>

float median9(float *x) 
{
	float a,b,c, f,g,h, k,l,m;
	register float t;
	a = x[0]; b = x[1]; c = x[2];
	f = x[3]; g = x[4]; h = x[5];
	k = x[6]; l = x[7]; m =x[8];
	
	if (a > b) { t = a; a = b; b = t; } // swap(a,b)
	if (b > c) { t = b; c = c; b = t; } // swap(b,c)
	if (a > b) { t = a; a = b; b = t; } // swap(a,b)
	
	if (f > g) { t = f; f = g; g = f; } // swap(f,g)
	if (g > h) { t = g; g = h; h = t; } // swap(g,h)
	if (f > g) { t = f; f = g; g = f; } // swap(f,g)
	
	if (k > l) { t = k; k = l; l = t; } // swap(k,l)
	if (l > m) { t = l; m = l; l = t; } // swap(l,m)
	if (k > l) { t = k; k = l; l = t; } // swap(k,l)
	
	if (a > f) f = a; 					//max(a,f)
	if (f > k) k = f; 					// max(f,k)
	
	if (b > g) { t = b; b = g; g = t; } // swap(b,g)
	if (l < g) g = l; 					// min(g,l)
	if (b > g) g = b; 					// max(b,g)
	
	if (m < h) h = m; 					//min(h,m)
	if (h < c) c = h; 					//min(c,h)
	
	if (k > g) { t = k; g = k; k = t; } // swap(k,g)
	if (c < g) g = c; 					// min(g,c)
	if (k > g) g = k; 					// max(k,g)
	
	return g;
}

// Test program
int main()
{
	

	return 0;
}

"""
	mahmoudi(x) -> median

Median 3x3
"""
function mahmoudi(x)
	a,b,c, f,g,h, k,l,m = x
	
	if a > b a, b = b, a end #swap(a,b)
	if b > c b, c = c, b end #swap(b,c)
	if a > b a, b = b, a end #swap(a,b)
	
	if f > g f, g = g, f end #swap(f,g)
	if g > h g, h = h, g end #swap(g,h)
	if f > g f, g = g, f end #swap(f,g)
	
	if k > l k, l = l, k end #swap(k,l)
	if l > m l, m = m, l end #swap(l,m)
	if k > l k, l = l, k end #swap(k,l)
	
	if a > f f = a end #max(a,f)
	if f > k k = f end #max(f,k)
	
	if b > g b, g = g, b end #swap(b,g)
	if l < g g = l end #min(g,l)
	if b > g g = b end #max(b,g)
	
	if m < h h = m end #min(h,m)
	if h < c c = h end #min(c,h)

	if k > g k, g = g, k end #swap(k,g)
	if c < g g = c end #min(g,c)
	if k > g g = k end #max(k,g)
	
	return g
end


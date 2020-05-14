# (C) Emmanuel Brandt 2020 <wizebt@gmail.com>

# @swap(x,y)
macro swap(x,y)
    quote
        $(esc(x)), $(esc(y)) = $(esc(y)), $(esc(x))
    end
end

"""
	 qm3(x) -> median of 3 elements

Input 3, delay 3, comparison 3.
"""
function qm3(x)
    a, b, c = x

    if a > b a, b = b, a end
    if c < b b = c end
    
    return a < b ? b : a
end

"""
	qm4(x) -> median of 4 elements

Imput 4, delay 3, comparisons 4.
"""
function qm4(x)
	a, b, c, d = x
	
	if a > b a, b = b, a end; if c > d c, d = d, c end
	if d < b b = d end; if a > c c = a end
	
	return 0.5(b + c)
end

"""
	qm5(x) -> median of 5 elements

Input 5, delay 6, comparison 8.
"""
function qm5(x)
    a, b, c, d, e = x

    if b > c b, c = c, b end
    if d > e d, e = e, d end
    if b > d b, d = d, b end
    if a > c a, c = c,a end
    if c > e c = e end
    if a > d a, d = d, a end
    if a > b b = a end
    if c > d c = d end

    return b > c ? b : c
end

"""
	qm6(x) -> median of 6 elements

Input 6, delay 6, comparison 11.
"""
function qm6(x)
    a, b, c, d, e, f = x

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
end

"""
	qm7(x) -> median of 7 elements

Imput 7, delay , comparison .
"""
function qm7(x)
    a, b, c, d, e, f, g = x

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
end

"""
	qm9(x) -> median of 9 elements

Mahmoudi's triple sorter median algorithm, 19 comparison.
"""
function qm9(x)
    a, b, c, f, g, h, k, l, m = x

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

"""
	mahmoudi(x) -> median of 9 elements.

Median of 9 elements, no sort, minimum 19 comparisons.
Algorithm from Mahmoudi Z algorithm.
"""
function mahmoudi(x)
    a, b, c, f, g, h, k, l, m = x

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

"""
	sort9(a) -> a in-place sort

In-place sort, 19 comparison.
"""
function sort9(a)     # 30x min/max
    swap(a, i, j) =
        if a[i] > a[j]
            a[i], a[j] = a[j], a[i]
        end

    swap(a, 1, 2)
    swap(a, 4, 5)
    swap(a, 7, 8)
    swap(a, 2, 3)
    swap(a, 5, 6)
    swap(a, 8, 9)
    swap(a, 1, 2)
    swap(a, 4, 5)
    swap(a, 7, 8)
    swap(a, 1, 4)
    swap(a, 4, 7)
    swap(a, 2, 5)
    swap(a, 5, 8)
    swap(a, 2, 5)
    swap(a, 6, 9)
    swap(a, 3, 6)
    swap(a, 3, 5)
    swap(a, 5, 7)
    swap(a, 3, 5)

    return a
end

"""
	median33filter(I::Array{Float32,2}) -> median

"""
function median33filter(I::Array{Float32,2})
    h, w = size(I)
    J = Array{Float32,2}(undef, h, w)
    J[[1, h], :] .= 0.0f0
    J[:, [1, w]] .= 0.0f0

    for j = 2:w-1, i = 2:h-1
        J[i, j] = mahmoudi(I[i-1:i+1, j-1:j+1])
    end

    return J
end

"""
	medianhistogram(x::Array{Float32}; nbins::Int=256) -> median

Work in progress. Image median filter using sliding window and histogram
Median Filtering in constant time.
Simon Perrauult and Patrick Hebert
"""
function mh(x::Array{Float32}, nbins::Int)
    n = length(x)
    h = zeros(Int, nbins)
    c = Float32(nbins - 1)

    for i = 1:n
        h[1 + round(Int, x[i] * c)] += 1
    end
    println(h)

    k = div(n, 2)
    i = 1
    a = h[i]

    while c < k
        i += 1
        a += h[i]
    end

    return i
end

"""
	qm3(x) -> median of 3 elements

Fastest quick median 3, minimum number of comparisons.
"""
function qm31(x::Array)
    @inbounds if x[1] > x[2]
        if x[2] > x[3]
            return x[2]
        elseif x[1] > x[3]
            return x[3]
        else
            return x[1]
        end
    else
        if x[1] > x[3]
            return x[1]
        elseif x[2] > x[3]
            return x[3]
        else
            return x[2]
        end
    end
end

"""
	 qm31(x) -> median of 3 elements

"""
function qm32(x)
    @inbounds begin
        a = x[1] - x[2]
        (x[2] - x[3])a > 0 && return x[2]
        (x[1] - x[3])a > 0 && return x[3]
        return x[1]
    end
end

"""
	qm3swap(x::Array{Float32,1}) -> median of 3 elements

In-place sort, sort by network in constant time.
"""
function qm33(x)
    @inbounds begin
        if x[1] > x[2]
            x[1], x[2] = x[2], x[1]
        end

        if x[2] > x[3]
            x[2], x[3] = x[3], x[2]
        end

        if x[1] > x[2]
            x[1], x[2] = x[2], x[1]
        end

        return x[2]
    end
end

"""
	qm32(x) -> median of 3 elements

Input 3, exhaustive set of comparisons.
"""
function qm34(x)
    a, b, c = x

    return a < b ? c > b ? (a > b ? a : b) : (a > c ? c : a) :
           a < c ? (b > a ? b : a) : (b > c ? b : a)
end

function med34(I)
    return mapwindow(median, I, (3, 3))
end

"""
	quickmedian(a) -> median

Quick median is a partial quicksort from Tony Hoare.
For odd size array median = n/2+1.
Non recursive implementation (average x2 speed of quick sort) as
only half array is sorted.
"""
function quickmedian(a)
	n = length(a)
	k = (n >> 1) + 1
	left = 1
	right = n

	while left <= right
		pivot = a[div(left+right, 2)]
		j = left
		for i = left:right
			if a[i] < pivot
				a[i], a[j] = a[j], a[i]
            	j += 1
         	end
		end
		a[right], a[j] = a[j], a[right]

		if j == k
			break
		elseif j < k
			left = j + 1
		else
			right = j - 1
		end
   end

   return a[k]
end

"""
	twpqs(a::Array) -> median

Three-Way Partition Quick Median, in-place sorting to half size.
A combination of Quick Median from Tony Hoare and Deutch Flag algorithm 
from Edsger Dijkstra.
- `a::Array`: even length.
"""
function twpqm(a::Array)
    n = length(a)
    iseven(n) && return

    left = l = j = 1
    right = r = n
    k = 1 + n >> 1 # final median index
    pivot = a[k] # initial pivot value

    # Partion elements: lower than, equal, greater than pivot
    @inbounds while left <= right
        while j <= r
            if a[j] < pivot
                a[j], a[l] = a[l], a[j]
                l += 1
                j += 1
            elseif a[j] > pivot
                a[j], a[r] = a[r], a[j]
                r -= 1
            else
                j += 1
            end
        end

        if k > r
            left = l = j = r + 1
            r = right
        elseif k < l
            r = right = l - 1
            l = j = left
        else
            return pivot
        end

        pivot = a[(l+r)>>1]
    end
end

"""
	med3filter(I) -> img

Input 3, Separable fast median filter 3x3.
"""
function med3filter(I)
    h, w = size(I)
    n = h * w
    J = Array{Float32,2}(undef, h, w)

    for i = 2:n-1
        J[i] = qm3([I[i-1], I[i], I[i+1]])
    end

    for i = 1+h:n-h
        J[i] = qm3([J[i-h], J[i], J[i+h]])
    end

    return J
end

"""
    gfilter(I) -> gaussian filtered array

Fast gaussian filter
-`I::Array{2}`: Image
"""
function gfilter(I)
    g = [0.40261996f0 0.24420136f0 0.05448869f0]
    h, w = size(I)
    n = h * w
    z = 0.0f0
    J = Array{Float32,2}(undef, h, w)

    for i in [1 2 n - 1 n]
        J[i] = z
    end

    @inbounds for i = 3:n-2
        J[i] = I[i] * g[1] + (I[i-1] + I[i+1]) * g[2] + (I[i-2] + I[i+2]) * g[3]
    end

    K = Array{Float32,2}(undef, h, w)
    @inbounds for i = 1+2h:n-2h
        K[i] =
            J[i] * g[1] + (J[i-h] + J[i+h]) * g[2] + (J[i-2h] + J[i+2h]) * g[3]
    end

    @inbounds for i = 1:2h
        K[i] = K[n+1-i] = K[i+2h]
    end

    return K
end

# Validation section for the above functions.
# use meta programming to make one test fct.
using Combinatorics, Statistics

function t9()
    i = 0
    for x in permutations(1:9)
        m1 = qm9(x)
        m2 = round(Int, median(x))

        if m1 != m2
            println("$x $m1 $m2")
            break
        end
        i += 1
    end

    return i
end

function t7()
    i = 0
    for x in permutations(1:7)
        m1 = qm7(x)
        m2 = round(Int, median(x))

        if m1 != m2
            println("$x $m1 $m2")
            break
        end
        i += 1
    end

    return i
end

function t6()
    i = 0
    for x in permutations(1:6)
        m1 = qm6(x)
        m2 = median(x)

        if m1 != m2
            println("$x $m1 $m2")
            break
        end
        i += 1
    end

    return i
end

function t4()
    i = 0
    for x in permutations(1:4)
        m1 = qm4(x)
        m2 = median(x)

        if m1 != m2
            println("$x $m1 $m2")
            break
        end
        i += 1
    end

    return i
end

function t5()
    i = 0
    for x in permutations(1:5)
        m1 = qm5(x)
        m2 = round(Int, median(x))

        if m1 != m2
            println("$x $m1 $m2")
            break
        end
        i += 1
    end

    return i
end

function t3()
    i = 0
    for x in permutations(1:3)
        m1 = qm3(x)
        m2 = round(Int, median(x))

        if m1 != m2
            println("$x $m1 $m2")
            break
        end
        i += 1
    end

    return i
end

"""
	tqm()

Test quickmedian on all permutations against median.
"""
function tqm(n::Int)
    i = 0
    for x in permutations(1:n)
        m1 = quickmedian(x)
        m2 = round(Int, median(x))

        if m1 != m2
            println("$x $m1 $m2")
            break
        end
        i += 1
    end

    return i
end

# Test data for fast 3x3 gaussian filter
using ImageFiltering
gk2 = Kernel.gaussian(2.0f0);
g = collect(gk2);

# Test image
I = rand(Float32, 60, 80);
I[11:19, 21:29] .+= 50g; # star centroid 15,25
I[41:49, 51:59] .+= 100g; # star centroid 45,55
# Add 10% random hot pixels
for i = 1:400 I[rand(1:60), rand(1:80)] += 9.0f0 * rand(Float32) end

using ImageView
imshow(I, name = "Test image")
imshow(mapwindow(qm9, I, (3, 3)), name = "mapwindow qm9")
imshow(mapwindow(median, I, (3, 3)), name = "mapwindow median 3x3")

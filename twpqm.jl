"""
	twpqs(a::Array) -> median

Three-way partition Quick Median, in-place sorting.
A combination of Quick Median from Tony Hoare and
the Deutch Flag algorithm from Edsger Dijkstra.
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
        while j <= r#
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

using Statistics, Combinatorics, BenchmarkTools

function ttwpqm()
	A = rand(Float32.(1:9),99)
	twpqm(A)
end

function t3wp(n::Int)
    i = 0
    for a in permutations(1:n)
    #for j = 1:n a = rand(1:9, 99)
        m1 = twpqm(a)
        m2 = round(Int, median(a))
        if m1 != m2
            println("$a twpqm $m1 median $m2")
            break
        end
        i += 1
    end
    println(i)
end

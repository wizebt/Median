# (C) Emmanuel Brandt 2017-20 <wizebt@gmail.com>

"""
	quickmedian(a) -> median

Quick median is a partial quicksort from Tony Hoare.
For odd size array median = n/2+1.
Non recursive implementation (average x2 speed of quick sort) as
only half array is sorted.
"""
function quickmedian(a)
	n = length(a)
	k = 1 + n >> 1
	left = 1
	right = n

	while left <= right
		# for large file use pivot median of 5
		# Critial to avoid O(n2) worse case complexity.
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

function quickmedian(a)
	n = length(a)
	k = (n >> 1) + 1
	left = 1
	right = n

	while left <= right
		# for large file use pivot median of 5
		# Critial to avoid O(n2) worse case complexity.
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

function quickselect(a::Array, k::Int)
	n = length(a)
	left = 1
	right = n

	while left <= right
		# for large file use pivot median of 5
		# Critial to avoid O(n2) worse case complexity.
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
	tqm()

Test quickselect on all permutations against median.
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



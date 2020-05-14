"""
 * quickmedian returns the median from an array of int of size n
 * Derived from original quickselect algorithm from Tony Hoare
 * non recurssive version modified to return the median value
 * Written by Emmanuel Brandt 2019-02
 * @param a array of int
 * @param n array size
 * @return median value as double
"""
function quickmedian(a)
	n = length(a)
	k = 1 + div(n, 2) 	# size to sort
	left = 1 	# left index
	right = 9 	# right index

	while left < right 	# we stop when our indicies have crossed
		pindex = div(left + right, 2) # pivot selection, this can be whatever
		
		pivot = a[pindex]
		a[pindex] = a[right]
		a[right] = pivot # SWAP

		pindex = left
		for i = pindex:right-1
			if a[i] < pivot 
				a[pindex], a[i] = a[i], a[pindex] # SWAP (pindex, i)
				pindex += 1
			end
		end
		
		# SWAP values
		a[right] = a[pindex]
		a[pindex] = pivot; 

		if pindex < k
			left = pindex + 1
		else # pindex >= k
			right = pindex
		end
	end
	
	return a[k]
end

function tqm()
	A = rand(Float32.(1:9),999)
	quickmedian(A)
end

function twpqs(a)
	n=length(a)
	left=l=j=1
	right=r=n
	k=div(n+1,2) # pivot index
	p=a[k] # pivot value

	while left<=right
		while j<=r # 3 way partition < = >
			if a[j]<p
				a[j],a[l]=a[l],a[j] # swap a[j] a[l]
				l+=1
				j+=1
			elseif a[j]>p
				a[j],a[r]=a[r],a[j] # swap a[j] a[r]
				r-=1
			else
				j+=1
			end
		end

		if k>r
			left=l=j=r+1
			r=right;
		elseif k<l
			r=right=l-1;
			l=j=left
		else
			#if n%2==0 and k<=l
				#return (p+max(a[0:k]))/2
			return p
		end
		p=a[div(l+r,2)]
	end
end

import Statistics.median
for i=1:9
	a=rand(1:9,1,19)
	#println(a)
	m1=median(a)
	m=twpqs(a)

	if m==m1
		println(m,a)
	else
		println("error",m," median ",m1)
		println(a)
	end
end

function med3(a)
	if a[1] < a[2]
		if a[2] < a[3] 
			m=a[2]; # 2 comp, order a,b,c
		elseif a[1] < a[3] 
			m=a[3]; # 3 comp, order a,c,b
		else 
			m=a[1]; # order c,a,b
		end
	else
		if a[3] < a[2] # order c,b,a
			m=a[2];
		elseif a[1] < a[3] 
			m=a[1]; # order b,a,c
		else 
			m=a[3]; # order b,c,a
		end
	end
	a[2]
end

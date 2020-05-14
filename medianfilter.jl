# Step  Row machine for median filter — “row sort”

if RS1 > RS0 # Compare “k” with “l”
	Tmp = RS0
	Med = RS1
else
	Tmp = RS1
	Med = RS0  # “Med” is a temporary variable
end

RS1 = RS0 			# Update row state register RS1
RS0 = Input[j][i] 	#Fetch the next pixel from the input image

if RS0 < Med
	Max = Med # “Max” is the row maximum
	Med = RS0 
else 
	Max = RS0
end

if Med < Tmp 
	Min = Med
	Med = Tmp # “Med” is the row median
else 
	Min = Tmp # row minimum
end

# Column machine part 1 — finding MaxMin = the maximum of the minimums
if CS5[i] > CS4[i] 
	MaxMin = CS5[i]
else 
	MaxMin = CS4[i] # “MaxMin” is a temporary variable here
	CS5[i] = CS4[i] # Update column state register CS5[i]
	CS4[i] = Min 	# Save the row machine minimum in CS4[i]
end

if CS4[i] > MaxMin 
	MaxMin = CS4[i] # MaxMin = max of row minimums
end

# Column machine part 2 — finding MedMed = the median of the medians
if CS3[i] > CS2[i] 
	Tmp = CS2[i]
	MedMed = CS3[i]
else 
	Tmp = CS3[i]
	MedMed = CS2[i]	# “MedMed” is temporary here
	CS3[i] = CS2[i] # Update column state register CS3[i]
	CS2[i] = Med	# Save the row machine median in CS2[i]
end

if CS2[i] < MedMed
	MedMed = CS2[i]	# “MedMed” is temporary here
end

if Tmp > MedMed
	MedMed = Tmp	# “MedMed” = median of row medians
end

# Column machine part 3 — finding MinMax = the minimum of the maximums
if CS1[i] < CS0[i]
	MinMax = CS1[i]
else 
	MinMax = CS0[i]	 # “MinMax” is a temporary variable here
	CS1[i] = CS0[i]	# Update column state register CS1[i]
	CS0[i] = Max	# Save the row machine maximum in CS0[i]
end

if CS0[i] < MinMax
	MinMax = CS0[i]	# MinMax = min of row maximums
end

# Column machine part 4 — finding the median of Parts 1, 2, & 3 above
if MedMed > MaxMin
	Median = MedMed
	Tmp = MaxMin
else
	Median = MaxMin
	Tmp = MedMed
end
20 if (MinMax < Median) Median = MinMax;
21 if (Tmp > Median) Median = Tmp; //“Median” = desired filter output
22 Output[j-1][i-1] = Median; // Write output, compensating for latency

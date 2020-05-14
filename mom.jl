function mom(a)
    step=1
    size=9
    for r=1:2
        i=div(step+1,2)
        #println("step=",step," r=",r," i=",i)
        while i<=size
            j=i+step
            k=i+2*step
            #println("r=",r," i=",i," j=",j," k=",k)
            if a[i]<a[j]
                if a[k]<a[i]
                    a[i],a[j]=a[j],a[i]
                elseif a[k]<a[j]
                    a[j],a[k]=a[k],a[j]
                end
            else
                if a[i]<a[k]
                    a[i],a[j]=a[j],a[i]
                elseif a[k]>a[j]
                    a[j],a[k]=a[k],a[j]
                end
            end
            i+=3*step
        end
        step=3*step
        #println("r=",r," step=",step,a)
    end
    return a[5]
end

import Statistics.median

for i=1:99
    a=rand(1:255,1,9)
    #a=[1,2,3,4,5,6,7,8,9]
    #a=[1,2,3,1,3,2,2,3,1]
    #a=[2,1,3,3,1,2,3,2,1]
    m=mom(a)
    m1=median(a)
    # println(m," ",m1," ",a)
    if m1!=m
        println("Diff ",m," ",m1," ",a)
    end
end

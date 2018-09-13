n = 1000000000000000
ans = 0
currAns = 0
j = 1
i = (n-1)**(1/3)
i = int(i)
print(i)
while(i>0):
    sb = n-i*i*i
    while(sb>=j*j):
        currAns+=(j-1)*(2*j-1)
        j+=1
    ans+=currAns+(j-1)*(sb-(j-1)*(j-1))
    if(i%100==0):
        print(n-i*i*i)
    i-=1
print(ans)

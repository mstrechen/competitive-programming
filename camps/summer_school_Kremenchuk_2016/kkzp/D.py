def a(b):
    ans = 0
    i = 1
    while(i*i<b):
        ans+=b-i*i
        i+=1
    return ans
ans = 0
i = 1
n = 1000000000000
while(i*i*i<n):
    if(i%100==0):
        print(n-i*i*i)
    ans+=a(n-i*i*i)
    i+=1
print(ans)
	

a = input().split()
k = int(a[0])
n = int(a[1])

b = [0]*601
b[0] = 1
i = 0
while(i<n):
    j = 1
    while(j<=k):
        b[i+j]+=b[i]
        j+=1
    i+=1

print(b[n])

a = input().split()
n = int(a[0])
k = int(a[1])
i2 = 1
b = input().split()
summ = 0
i = 0
while(i<n):
    a[i] = int(a[i])*i2
    i2*=2
    summ+=a[i]
    i+=1
print(summ)


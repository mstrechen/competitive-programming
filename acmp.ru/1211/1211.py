def gcd(a,b):
    if(a!=0) and (b!=0):
        return gcd(b,a%b)
    return a+b

def lcm(a,b):
    return a*b//gcd(a,b)

def get(a,n,b,m,x):
    return (a+b)*x - (x//n)*a - (x//m)*b + (x//lcm(n,m))*(a+b)
tmp = input().split(' ')

a = int(tmp[0])
n = int(tmp[1])
b = int(tmp[2])
m = int(tmp[3])
x = int(tmp[4])

l = 1
r = 1000000000000000000000000000000000000

while(l+1<r):
    mid = (l+r-1)//2 + 1
    if(get(a,n,b,m,mid)<x):
        l = mid
    else:
        r = mid
print(r)


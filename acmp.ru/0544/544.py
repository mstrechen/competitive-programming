n = int(input())
a,b,c = 0,0,1
while n:
    a,b,c = b,c,a+b+c
    n-=1
print(c)

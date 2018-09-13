import math
n, m = map(int,raw_input().split())

if(n>m):
    n,m = m,n

n+=1
m+=1

ans = 0;
for i in range(1, n):
    ans+=i*(n-i)*(m-i)

len = 0;
while(ans):
    len+=1
    ans//=10
print(len)

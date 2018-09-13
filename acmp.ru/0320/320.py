m, n = map(int, input().split())
d = [1]+[0]*99
for i in range(n):
    d[i+1]+=d[i]
    d[i+m]=d[i]
print (d[n])

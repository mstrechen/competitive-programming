n = int(input())

a = [0]*n
d = {}

for i in range(n):
    tmp = eval(input())
    a[i] = tmp
    d[tmp] = d.get(tmp, 0) + 1

for i in a:
    print(d.get(i, 0), end = ' ')

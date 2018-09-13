input()
a = 0
b = 0
c = 0
for i in input().split():
    t = int(i)
    a+=t*b
    b+=t*c
    c+=t
print(a)

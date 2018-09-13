n = int(input())-1
l = 0
while n:
        l^=n%3==2
        n//=3 
print(l)

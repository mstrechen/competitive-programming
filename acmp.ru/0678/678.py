n = int(input())
def ans(n):
    if n==3:
        return 1
    if n<3:
        return 0
    else:
        return ans((n-1)/2+1)*2
print(ans(n))

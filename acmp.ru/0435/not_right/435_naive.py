def isOk(n):
    n = str(n)
    sL = 0
    sR = 0
    for i in n:
        sR+=int(i)
        if(i>'3'):
            return 0
            

    if(sR == sL):
        return 1

    for i in n:
        sR-=int(i)
        sL+=int(i)
        if(sR == sL):
            return 1

    return 0

ans = 0
for i in range(0, 10000):
    if(isOk(i)):
        print(i)
        ans+=1
print(ans)

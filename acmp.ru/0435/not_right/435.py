countOfVars = []

def makecount(n, maxdigit):
    global countOfVars
    countOfVars = [0]*n*maxdigit
    for i in range(0, n*maxdigit):
        countOfVars[i] = [0]*(n+1)

    for i in range(0, n+1):
        countOfVars[0][i] = 1;

    for s in range(1, n*maxdigit):
        for c in range(1, n+1):
            for last in range(0, min(maxdigit,s)+1):
                countOfVars[s][c]+=countOfVars[s-last][c-1]

def getcount(count,total):
    global countOfVars
    return countOfVars[total][count]


n, maxdigit = map(int, input().split())
makecount(n, maxdigit)

res = 1

for i in range(1, n):
    for curS in range(0, min(i, n-i)*maxdigit + 1):
        for delta in range(0, 2):
            if(delta%2==0):
                res+=getcount(i-delta, curS)*getcount(n-i, curS)
            else:
                res-=getcount(i-delta, curS)*getcount(n-i,curS)
print((maxdigit + 1)**n - res)
    

x1, y1, x2, y2 = map(int, raw_input().split())

deltaX = abs(x1-x2)
deltaY = abs(y1-y2)
minDelta = min(deltaX,deltaY)
maxDelta = max(deltaX,deltaY)


fact = [0]*(maxDelta+1)
fact[0] = 1

i = 1

while(i<=maxDelta):
    fact[i] = fact[i-1]*i
    i+=1


positive = minDelta
negative = 0

res = 0
while(positive+negative <=maxDelta):
    res+=fact[maxDelta]//(fact[maxDelta-positive-negative]*fact[positive]*fact[negative])
    positive+=1
    negative+=1
print(res)    

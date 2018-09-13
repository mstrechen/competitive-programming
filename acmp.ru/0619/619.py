N, total = map(int, input().split(' '))


dpCur = [0]*(N*6+1)

dpCur[0] = 1

for i in range(N):
    dpNext = [0]*(N*6+1)
    for j in range(i*6+1):
        for delta in range(1,7):
            dpNext[j+delta]+=dpCur[j]/6
    dpCur = dpNext
print(dpCur[total])

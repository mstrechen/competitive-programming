maxScore, A, B, money = map(int, input().split(' '))

dp = [0]*51

for i in range(51):
    dp[i] = [0]*51

dp[A][B] = money* 2**64

for i in range(0, maxScore+1):
    for j in range(0, maxScore+1):
        if(i<maxScore):
            if(j<maxScore):
                dp[i][j+1]+=dp[i][j]//2
                dp[i+1][j]+=dp[i][j]-dp[i][j]//2
            else:
                dp[i+1][j]+=dp[i][j]
        else:
            if(j<maxScore):
                dp[i][j+1]+=dp[i][j]

print(dp[maxScore][maxScore-1]//2**64, dp[maxScore-1][maxScore]//2**64)


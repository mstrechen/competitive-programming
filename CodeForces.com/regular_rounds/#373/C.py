l, s = map(int, input().split())

pre, su = input().split('.')

dp = [2000*1000*1000]*len(su)
if(su[len(su)-1] > '4'):
    dp[len(su)-1] = 1

for i in range(len(su)-2, -1, -1):
    if(su[i] > '4'):
        dp[i] = 1
    elif(su[i] == '4'):
        if(dp[i+1]!=2000*1000*1000):
            dp[i] = dp[i+1] + 1;
    
if(min(dp) == 2000*1000*1000):
    print(pre,su,sep = '.')
else:
    posSaved = -1
    for i in range(0, len(su)):
        if(dp[i] <= s) and (posSaved == -1):
            posSaved = i;
            valSaved = dp[i]
    if(posSaved == 0):
        print(int(pre) + 1)
    else:
        print(pre, int(su[:posSaved]) + 1, sep = '.')

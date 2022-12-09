T = int(input())
for _ in range(T):
    k = int(input())
    n = int(input())
    dp = [i for i in range(n+1)]
    for _ in range(k):
        for i in range(1,n+1):
            dp[i] += dp[i-1]
    print(dp[-1])
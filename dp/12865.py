import sys
input = sys.stdin.readline

N, K = map(int, input().split())
bag = [[0,0]]

for _ in range(N):
    W, V = map(int, input().split())
    bag.append([W,V])




dp = [[0 for _ in range(K+1)] for _ in range(N+1)]
for num in range(1,N+1):
    w,v = bag[num]
    for k in range(1,K+1):
        if k < w:
            dp[num][k] = dp[num - 1][k] 
        else:
            dp[num][k] = max(v + dp[num - 1][k - w], dp[num - 1][k])
print(dp[-1][-1])
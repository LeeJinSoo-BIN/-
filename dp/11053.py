N = int(input())
array = list(map(int, input().split()))

dp = [0 for _ in range(len(array))]

for i in range(N):
    max_ = 0
    for j in range(i+1):
        if array[i] > array[j] :
            max_ = max(max_, dp[j])
    dp[i] = max_+1
print(max(dp))
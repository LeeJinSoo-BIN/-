import sys; input = sys.stdin.readline

N, S = map(int, input().split())
arr = list(map(int, input().split()))


ans = N
flag = 0
for k in range(N):
    sum = 0
    cnt = 0
    for t in range(k,N):
        sum += arr[t]
        cnt += 1
        if sum >= S :
            if sum == S :
                flag = 1
                if cnt < ans :
                    ans = cnt
            break
        

if flag == 1:
    print(ans)
else :
    print(0)
        
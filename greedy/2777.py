T = int(input())

for _ in range(T):
    N = int(input())
    i = 9
    cnt = 0
    while(i>1):
        if N%i == 0:
            N /= i
            cnt += 1
        else :
            i -=1
    if cnt == 0 :
        if N == 1:
            print(1)
        else:
            print(-1)
    else:
        if N > 10 :
            print(-1)
        else :
            print(cnt)
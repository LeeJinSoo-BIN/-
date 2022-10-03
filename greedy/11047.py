N, K = map(int,input().split())


coin = []
for _ in range(N) :
    coin.append(int(input()))


cnt = 0
idx = N-1

while(idx>=0):    
    cnt += K // coin[idx]
    K -= K // coin[idx] * coin[idx]
    if(K==0):
        break
    idx -= 1
    
    
print(cnt)
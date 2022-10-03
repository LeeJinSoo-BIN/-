import sys
input = sys.stdin.readline
N, K = map(int,input().split())

doll = list(map(int, input().split()))


lion = []
for i, x in enumerate(doll):
    if x == 1:
        lion.append(i)
front = 0

ans = N
flag = 0
while front+K-1 < len(lion):        
    if (lion[front + K -1] - lion[front]) + 1< ans :
        ans = lion[front + K -1] - lion[front] + 1
        flag = 1
    front += 1
    

if flag == 0:
    print(-1)
else :
    print(ans)
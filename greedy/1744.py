#import heapq
#from collections import deque


N = int(input())

ans = 0
pos = []
neg = []
zero = []
for _ in range(N):
    x = int(input())
    if x == 1:
        ans+=x
    elif x < 0:
        neg.append(x)
    elif x>0:
        pos.append(x)
    else:
        zero.append(x)
    

pos.sort()
neg.sort(reverse=True)
if(len(neg)%2 ==1):
    if (len(zero)==0):
        ans+=neg.pop(0)
    else:
        neg.pop(0)

if(len(pos)%2==1):
    ans += pos.pop(0)

while(1):
    if len(pos)==0:
        break
    tmp1 = pos.pop()
    tmp2 = pos.pop()
    ans+= tmp1*tmp2

while(1):
    if len(neg) == 0:
        break
    tmp1 = neg.pop()
    tmp2 = neg.pop()
    ans+= tmp1*tmp2

print(ans)
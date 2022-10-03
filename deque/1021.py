from collections import deque

N, M = input().split()
Deque = deque([x+1 for x in range(int(N))])

M_ = map(int,input().split())

count = 0
#import pdb; pdb.set_trace()
for m in M_ :
    i = Deque.index(m)
    l = int(len(Deque) / 2)
    if i > l :        
        for _ in range(len(Deque)-i):
            Deque.appendleft(Deque.pop())
            count+=1
    else :
        for _ in range(i):
            Deque.append(Deque.popleft())
            count+=1
    if Deque[0] == m :
        Deque.popleft()
    else:
        print("?")
print(count)
    



k = int(input())
stack = []
for _ in range(k):
    n = int(input())
    if n :
        stack.append(n)
    else :
        stack.pop()
    
print(sum(stack))



'''
from collections import deque

deq = deque([])


k = int(input())
for _ in range(k):
    n = int(input())
    if n :
        deq.append(n)
    else :
        deq.pop()
    
print(sum(deq))
'''
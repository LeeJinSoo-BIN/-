from collections import deque
N = int(input())


card = deque([a+1 for a in range(N)])

while(len(card)>1):
    print(card.popleft(), end = " ")
    card.append(card.popleft())

print(card.pop())
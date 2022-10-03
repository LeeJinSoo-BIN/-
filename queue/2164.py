from collections import deque

N = int(input())
deck = deque([x+1 for x in range(N)])
   

while(1):
    if(len(deck)==1):
        print(deck.pop())
        break
    deck.popleft()
    deck.append(deck.popleft())
    
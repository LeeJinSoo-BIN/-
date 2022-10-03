import sys
input = sys.stdin.readline
from bisect import bisect_left, bisect_right

N = int(input().rstrip())
card = list(map(int,input().split()))
M = int(input())
test = list(map(int,input().split()))

card.sort()

for t in test:
    left = bisect_left(card,t)
    right = bisect_right(card,t)
    print(int(1&(right-left)), end=' ')
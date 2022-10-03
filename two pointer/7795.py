import sys
input = sys.stdin.readline
T = int(input())

for _ in range(T):
    len_A, len_B = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    A.sort()
    B.sort()
    sum = 0
    for b in B:
        for a in range(len_A):
            if b < A[a]:
                sum += (len_A - a)
                break
    print(sum)
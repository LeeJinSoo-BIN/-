import sys
input = sys.stdin.readline
N = int(input())
M = int(input())
material = list(map(int, input().split()))

cnt = 0
while(1):
    if len(material) <= 1 :
        break
    m1 = material.pop()
    for m2 in material :
        if m1 + m2 == M :
            cnt += 1
            material.remove(m2)
            break
print(cnt)
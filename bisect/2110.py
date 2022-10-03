import sys
input = sys.stdin.readline
N, C = map(int, input().split())
houses = []
for _ in range(N) :
    houses.append(int(input()))
 
houses.sort()
 

start = 1 
end = houses[-1] - houses[0]
ans = 1
 
while start <= end:
    count = 1
    mid = (start + end) // 2
    current = houses[0]
    for house_position in houses:
        if current + mid <= house_position: 
            count += 1
            current = house_position
    if count >= C:
        start = mid + 1
        ans = mid if mid >= ans else ans
    else:
        end = mid - 1
 
print(ans)

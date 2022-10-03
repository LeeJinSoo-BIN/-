import sys
input = sys.stdin.readline

M, N = map(int, input().split())

lenghts = list(map(int, input().split()))


start = 0
end = max(lenghts) 
ans = 0
while start <= end:
    mid = (start+end) // 2    
    people = 0

    if mid == 0:
        break
    
    for length in lenghts:
        if length >= mid:
            people += (length//mid)
    
    
    if people >= M:        
        start = mid + 1
        ans = mid
    else:
        end = mid - 1
        
print(ans)


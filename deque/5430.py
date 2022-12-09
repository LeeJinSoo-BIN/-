from collections import deque
import sys
T = int(input())


for _ in range(T):
    order = sys.stdin.readline().rstrip()
    N = int(input())
    array = sys.stdin.readline().rstrip()
    array = deque(array[1:-1].split(','))    
    
    err = 0
    rev = 1
    for ac in order:
        if ac=='R':
            rev*=-1
        else:
            if(N==0):
                print("error")
                err = 1
                break
            if(rev==1):
                array.popleft()
                N-=1
            else:
                array.pop()
                N-=1
    if (err) :
        continue
    if(rev==-1):
        array.reverse()
    if N == 0:
        print('[]')    
        continue
    ans = "["
    for x in array:
        ans+=x+","    
    print(ans[:-1]+']')
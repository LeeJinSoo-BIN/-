from collections import deque
import sys
T = int(input())


for _ in range(T):
    order = sys.stdin.readline().rstrip()
    _ = input()
    array = sys.stdin.readline().rstrip()
    array = deque(array[1:-1].split(','))
    err = 0
    rev = 1
    for ac in order:
        if ac=='R':
            rev*=-1
        else:
            if(len(array)==1):
                print("error")
                err = 1
                break
            if(rev==1):
                array.popleft()
            else:
                array.pop()
    if (err) :
        continue
    if(rev==-1):
        array.reverse()
    ans = "["
    for x in array:
        ans+=x+","    
    print(ans[:-1]+']')
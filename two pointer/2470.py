import sys
input = sys.stdin.readline
N = int(input())


liquid = list(map(int, input().split()))
liquid.sort()

front = 0
back = N-1

liquid1 = 0
liquid2 = 0
ans = 1000000000
while(front < back) :
    fusion = liquid[front] + liquid[back]    
    if abs(fusion) < ans :
        ans = fusion
        liquid1 = liquid[front]
        liquid2 = liquid[back]

    if (fusion) == 0 :        
        break
    elif fusion < 0 :        
        front += 1        
    else :        
        back -= 1
    

print(liquid1, liquid2)
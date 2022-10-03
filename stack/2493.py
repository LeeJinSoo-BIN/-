'''
import sys
N = int(input())
top = list(map(int, sys.stdin.readline().split()))    

ans = ""


while(1):
    if len(top) == 0 :
        break
    height = top.pop()
    
    N-=1
    n = N   
    
    while(1):
        if (n == 0):
           tmp = "0"
           ans = tmp+" "+ans
           break
        if(top[n-1]>=height):
            tmp = str(n)
            ans = tmp+" "+ans
            break
        n-=1
        
print(ans)
'''



N = int(input())
tops = list(map(int, input().split(' ')))    


index = 1
stack = []
for height in tops:
    if len(stack) != 0:
        while(stack[-1][0] < height):
            stack.pop()
            if(len(stack)==0):
                print("0",end=" ")
                break
        if(len(stack)!=0):
                print(stack[-1][1],end=" ")        
    else:
        print("0",end=" ")
    stack.append([height,index])
    index+=1

n = int(input())


stack = []
sequence_ = 1
d = ""
for x in range(n):
    num = int(input())
    while(1):
        if(sequence_ <= num):
            stack.append(sequence_)
            sequence_+=1
            d+="+\n"
        else:
            break    
    if(stack[-1]==num):
        stack.pop()
        d+="-\n"

    else:
        d="NO"
        break
print(d)
    
        
    

    





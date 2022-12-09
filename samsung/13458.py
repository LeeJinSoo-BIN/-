N = int(input())

rooms = list(map(int, input().split()))
main, sub = map(int, input().split())

total = 0
for room in rooms :
    total +=1
    if (room - main) > 0 :
        total += (room-main)//sub
        if (room-main)%sub > 0 :
            total += 1
print(total)
import sys
input = sys.stdin.readline
chemi = input()
stack = []

tmp = 0
total = 0
value = {'H':1,'C':12,'O':16}
for a in chemi :
    if a == 'H' or a =='C' or a=='O':
        tmp+=value[a]
    elif a == '(' :
        print(a)
    elif a ==')':
        stack.pop()


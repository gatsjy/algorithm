'''
4. 후위식 연산
'''
import sys
from collections import deque
#sys.stdin=open("input.txt", "r")
a=input()
stack=[]

for x in a:
    if x.isdecimal():
        stack.append(int(x))
    else:
        a=stack.pop()
        b=stack.pop()
        if x=='*':
            stack.append(b*a)
        elif x=='/':
            stack.append(b//a)
        elif x=='+':
            stack.append(b+a)
        elif x=='-':
            stack.append(b-a)

print(stack[-1])
'''
3. 후위 표기식 만들기
'''
import sys
from collections import deque
#sys.stdin=open("input.txt", "r")
a=input()
stack=[]
res=''
for x in a:
    if x.isdecimal():
        res += x
    else:
        if x=='(':
            stack.append(x)
        elif x=='*' or x=='/':
            while stack and (stack[-1]=='*' or stack[-1]=='/'):
                res+=stack.pop()
            stack.append(x)
        elif x=='+' or x=='-':
            while stack and stack[-1] != '(':
                res+=stack.pop()
            stack.append(x)
        elif x==')':
            while stack and stack[-1] != '(':
                res+=stack.pop()
            stack.pop()

while stack:
    res+=stack.pop()

print(res)
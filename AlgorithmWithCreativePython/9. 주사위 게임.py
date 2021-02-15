'''
주사위 게임
'''
import sys
#sys.stdin=open("input.txt","rt")

n = int(input())

min = -2147000000

while n>0:
    a,b,c=map(int,input().split())
    tmp = 0
    if a==b==c :
        tmp = 10000+a*1000
    elif a==b or b==c or c==a:
        if a==b:
            tmp = 1000+a*100
        elif b==c:
            tmp = 1000+b*100
        elif c==a:
            tmp = 1000+c*100
    else:
        tmp = max(a,b,c)*100
    if min < tmp:
        min=tmp
    n-=1

print(min)

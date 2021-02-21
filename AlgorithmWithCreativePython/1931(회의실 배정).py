'''
이분검색
'''
import sys
#sys.stdin=open("input.txt","rt")

n = int(input())
a =[]
for _ in range(n):
    s,e=map(int,input().split())
    a.append((s,e))

a.sort(key=lambda x:(x[1],x[0]))
et = 0
cnt = 0
for x,y in a:
    if et <= x:
        et=y
        cnt+=1

print(cnt)

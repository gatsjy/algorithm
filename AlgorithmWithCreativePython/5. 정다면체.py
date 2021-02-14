'''
정다면체
'''
import sys
#sys.stdin=open("input.txt","rt")

n,m = map(int, input().split())

ch = [0]*(n+m+3)
max = -2147000000
for i in range(1,n+1):
    for j in range(1,m+1):
        ch[i+j] += 1

for i in range(n+m+1):
    if ch[i]>max:
        max=ch[i]

for i in range(n+m+1):
    if ch[i]==max:
        print(i, end=' ')


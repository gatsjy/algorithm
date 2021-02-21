'''
¿ª¼ö¿­
'''
import sys
#sys.stdin=open("input.txt", "r")
n=int(input())
a=list(map(int,input().split()))
idx=[0]*(n+1)

for i in range(1,n+1):
    cnt = a[i-1]
    for j in range(1,n+1):
        if cnt==0:
            if idx[j]>0:
                continue
            idx[j]=i
            break
        if idx[j]==0:
            cnt-=1

for i in range(1,n+1):
    print(idx[i], end=' ')
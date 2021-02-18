'''
이분검색
'''
import sys
#sys.stdin=open("input.txt","rt")

n,m = map(int, input().split())
a = list(map(int,input().split()))

a.sort()

res = 0
lt = 0
rt = n-1
while lt<=rt:
    mid = (lt+rt)//2
    if a[mid] <= m:
        res = mid
        lt=mid+1
    else:
        rt=mid-1

print(res+1)
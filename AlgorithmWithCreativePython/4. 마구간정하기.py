import sys
#sys.stdin=open("input.txt", "r")
n, m=map(int, input().split())
a=[]
for _ in range(n):
    a.append(int(input()))

a.sort()
size = m-1
lt = 1
rt = max(a)
res = 0
while lt <= rt:
    mid = (lt+rt)//2
    idx = 0
    i = 1
    cnt = 0
    for j in range(i,n):
        if a[j]-a[idx] >= mid:
            cnt+=1
            idx = j
            i = j+1

    if cnt >= size:
        lt = mid+1
        res =mid
    else:
        rt = mid-1

print(res)
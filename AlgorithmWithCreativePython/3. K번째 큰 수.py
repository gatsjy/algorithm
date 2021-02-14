import sys
#sys.stdin=open("input.txt","rt")
n,k = map(int, input().split())
a = list(map(int, input().split()))

# 중복을 제거하는 자료구조 set
res = set()

for i in range(n):
    for j in range(i+1,n):
        for k in range(j+1,n):
            res.add(a[i]+a[j]+a[k])

res = list(res)
res.sort(reverse=True)
print(res[k-1])
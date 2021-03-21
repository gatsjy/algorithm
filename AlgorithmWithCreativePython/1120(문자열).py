import sys

#sys.stdin=open("input.txt","r")

a,b = input().split()

sizea=len(a)
sizeb=len(b)
n = sizeb-sizea
res = 2147000000
for i in range(n+1):
    tmp = 0
    for j in range(sizea):
        if a[j] != b[i:i+sizea][j]:
            tmp+=1
    res = min(res,tmp)

print(res)
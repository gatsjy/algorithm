'''
�̺а˻�
'''
import sys
#sys.stdin=open("input.txt","rt")

n,m = map(int, input().split())

a =[]
for _ in range(n):
    a.append(int(input()))

lt = 1
rt = max(a)
mid = 0
res = 0
while lt<=rt :
    mid = (lt+rt)//2
    cnt = 0
    for i in a:
        cnt += i//mid

## �ִ밪�϶� �ּҰ��϶� �ٸ��� �����ؾ� �Ѵ�!!!!
    if cnt >= m:
        res = mid
        lt = mid+1
    else:
        rt = mid-1

print(res)        

'''
1166/น้มุ/C++
'''
import sys
#sys.stdin=open("input.txt","rt")

N,L,W,H = map(int,input().split())

s = 1
e = L*W*H//N
gubun = L*W*H//N
print(e)
print(gubun)
res = 0
while s <= e:
    mid = (s+e)//2
    if mid * mid * mid <= gubun:
        res = mid
        s = mid+1
    else:
        e = mid-1
print('%0.9f'%(res))

'''
´ëÇ¥°ª
'''
import sys
#sys.stdin=open("input.txt","rt")

n = int(input())
arr = list(map(int, input().split()))
average = round(sum(arr)/n)
min=2147000000
res = 0;
for idx, x in enumerate(arr):
    tmp = abs(x-average)
    if tmp <min:
        min = tmp
        score = x
        res = idx+1
    elif tmp == min:
        if x>score:
            score = x
            res = idx+1

print(average, res)
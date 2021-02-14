'''
ÀÚ¸´¼öÀÇ ÇÕ
'''
import sys
#sys.stdin=open("input.txt","rt")

def digit_sum(x):
    tmp = 0
    for i in str:
        tmp += ord(i)-48
    return tmp

n = int(input())
a = list(input().split())

max = -2147000000
res = a[0]
for str in a:
    tmp = digit_sum(str)

    if tmp > max:
        max = tmp
        res = str

print(res)
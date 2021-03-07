import sys
from collections import defaultdict
#input = sys.stdin.readline
sys.stdin=open("input.txt","r")
n = int(input())
s = dict()

for _ in range(n):
    a,b = map(str,input().split())
    if b == "enter":
        s[a] = 1
    else:
        del s[a]

res = sorted(s.keys(), reverse=True)
for x in res:
    print(x)
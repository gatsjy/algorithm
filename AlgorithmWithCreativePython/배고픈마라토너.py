import sys
from collections import defaultdict
#input = sys.stdin.readline
sys.stdin=open("input.txt","r")
n = int(input())
s=defaultdict(int)
for _ in range(n):
    ins = input()
    s[ins]+=1

for _ in range(n-1):
    ins = input()
    s[ins]-=1
    
for key,value in s.items():
    if value==1:
        print(key)
        break
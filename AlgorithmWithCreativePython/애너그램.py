import sys
from collections import deque
from collections import defaultdict
import heapq
import copy
#sys.stdin=open("input.txt", "r")

n=int(input())

for _ in range(n):
    ach=defaultdict(int)
    bch=defaultdict(int)
    a,b = input().split()
    for x in a:
        ach[x]+=1
    for x in b:
        bch[x]+=1
    
    if ach==bch:
        print("%s & %s are anagrams." %(a,b))
    else:
        print("%s & %s are NOT anagrams." %(a,b))

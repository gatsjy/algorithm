'''
set 자료형 이용하기
'''
import sys
sys.stdin=open("input.txt", "r")

asize = int(input())
a = set(map(int,input().split()))
bsize = int(input())
b = list(map(int,input().split()))

for x in b:
    if x in a:
        print("yes")
    else:
        print("no")
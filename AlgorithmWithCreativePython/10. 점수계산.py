'''
10. 점수 계산
'''
import sys
#sys.stdin=open("input.txt","rt")

n = int(input())
a = list(map(int,input().split()))

sum = 0
score = 1
for i in a:
    if i == 1:
        sum += score
        score += 1
    else:
        score=1

print(sum)
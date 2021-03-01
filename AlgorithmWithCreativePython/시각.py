'''
시각
'''
import sys
sys.stdin=open("input.txt", "r")

n = int(input())
cnt=0

print(str(30)[-2])
# n을 입력하면 00시00분00초 ~ 03시59분59초까지 달려간다.
for hour in range(n+1):
    for minute in range(60):
        for second in range(60):
            if '3' in str(hour) + str(minute) + str(second):
                cnt +=1 
print(cnt)
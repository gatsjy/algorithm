'''
�ð�
'''
import sys
sys.stdin=open("input.txt", "r")

n = int(input())
cnt=0

print(str(30)[-2])
# n�� �Է��ϸ� 00��00��00�� ~ 03��59��59�ʱ��� �޷�����.
for hour in range(n+1):
    for minute in range(60):
        for second in range(60):
            if '3' in str(hour) + str(minute) + str(second):
                cnt +=1 
print(cnt)
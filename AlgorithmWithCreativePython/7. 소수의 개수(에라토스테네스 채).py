'''
7. �Ҽ��� ����(�����佺�׳׽� ü)
'''
import sys
#sys.stdin=open("input.txt","rt")

n = int(input())

a = [0]*(n+1);

for i in range(2,n+1):
    for j in range(2*i,n+1,i):
        if a[j]==0:
            a[j]+=1
cnt = 0

for i in range(2,n+1):
    if a[i]==0:
        cnt += 1

print(cnt)

'''
11. ȸ�� ���ڿ� �˻�
'''
import sys
sys.stdin=open("input.txt","rt")
    
n = int(input())

for i in range(n):
    s=input()
    s=s.upper()
    size=len(s)
    ## ���ڿ� �Ųٷ� �ٲٱ� print(s[::-1])
    '''
    for j in range(size//2):
        if s[j] != s[-1-j]: # �� �̷� ��ų�� ����־� �Ѵ�!!
            print("#%d NO" %(i+1))
            break
    else:
        print("#%d YES" %(i+1))
    '''
    if s==s[::-1]:
        print("#%d YES" %(i+1))
    else:
        print("#%d NO" %(i+1))

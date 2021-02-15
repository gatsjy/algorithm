'''
11. 회문 문자열 검사
'''
import sys
sys.stdin=open("input.txt","rt")
    
n = int(input())

for i in range(n):
    s=input()
    s=s.upper()
    size=len(s)
    ## 문자열 거꾸로 바꾸기 print(s[::-1])
    '''
    for j in range(size//2):
        if s[j] != s[-1-j]: # 와 이런 스킬은 배워둬야 한다!!
            print("#%d NO" %(i+1))
            break
    else:
        print("#%d YES" %(i+1))
    '''
    if s==s[::-1]:
        print("#%d YES" %(i+1))
    else:
        print("#%d NO" %(i+1))

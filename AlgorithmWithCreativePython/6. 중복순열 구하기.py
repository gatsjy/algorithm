'''
6. 중복순열 구하기
'''
import sys
#sys.stdin=open("input.txt", "r")

def dfs(L):
    if L == m:
        for x in range(m):
            print(ch[x], end=' ')
        print()
        global cnt
        cnt+=1
    else:
        for i in range(1,n+1):
            ch[L]=i
            dfs(L+1)

if __name__=="__main__":
    n,m = map(int, input().split())
    ch = [0]*n
    cnt=0
    dfs(0)
    print(cnt)
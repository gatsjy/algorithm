'''
조합 구하기
'''
import sys
#sys.stdin=open("input.txt", "r")

def dfs(L, idx):
    global cnt
    if L==m:
        for i in range(m):
            print(p[i], end=' ')
        print()
        cnt+=1
    else:
        for i in range(idx,n+1):
            if ch[i-1]==0:
                ch[i-1]=1
                p[L]=i
                dfs(L+1, i+1)
                ch[i-1]=0
                
if __name__=="__main__":
    n,m = map(int,input().split())
    ch=[0]*(n+1)
    p=[0]*n
    cnt=0
    dfs(0,1)
    print(cnt)
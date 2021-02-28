'''
최대점수 구하기(DFS)
'''
import sys
sys.stdin=open("input.txt", "r")

def dfs(L, sum):
    global res
    if L==n+1:
        if sum > res:
            res = sum
    else:
        if L+t[L] <= n+1:
            dfs(L+t[L], sum+p[L])
        dfs(L+1,sum)

if __name__=="__main__":
    res = -217000000
    n = int(input())
    t = list()
    p = list()
    for _ in range(n):
        a,b =map(int,input().split())
        t.append(a)
        p.append(b)
    t.insert(0,0)
    p.insert(0,0)
    dfs(1,0)
    print(res)
'''
최대점수 구하기(DFS)
'''
import sys
#sys.stdin=open("input.txt", "r")

def dfs(L,sum, time):
    global res,a
    if time > m :
        return
    if L==n:
        if res < sum:
            res = sum
    else:
        dfs(L+1,sum+a[L][0], time+a[L][1])
        dfs(L+1,sum, time)

if __name__=="__main__":
    res = -2147000000
    n,m = map(int, input().split())
    a=[]
    for _ in range(n):
        s,t = map(int,input().split())
        a.append((s,t))
    dfs(0,0,0)
    print(res)
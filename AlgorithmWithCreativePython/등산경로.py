'''
등산경로(DFS)
'''
import sys
from collections import deque
#sys.stdin=open("input.txt", "r")

def dfs(x,y):
    global cnt
    if x==ex and y==ey:
        cnt+=1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<n and 0<=ny<n and ch[nx][ny]==0:
            if board[x][y] < board[nx][ny]:
                ch[nx][ny]=1
                dfs(nx,ny)
                ch[nx][ny]=0


if __name__=="__main__":
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    cnt = 0
    n = int(input())
    board=[list(map(int,input().split())) for _ in range(n)]
    #출발지는 가장 낮은 곳
    #목적지는 가장 높은 곳
    sx,sy,ex,ey =0,0,0,0
    sh = 2147000000
    eh = -2147000000
    for i in range(n):
        for j in range(n):
            if board[i][j] < sh:
                sx = i
                sy = j
                sh = board[i][j]
                
            if board[i][j] > eh:
                ex = i
                ey = j
                eh = board[i][j]

    ch = [[0]*n for _ in range(n)]
    ch[sx][sy]=1
    dfs(sx,sy)
    print(cnt)
'''
음료수 얼려먹기
'''
import sys
sys.stdin=open("input.txt", "r")
from collections import deque

def bfs(x,y):
    q = deque()
    q.append((x,y))
    while q :
        cur = q.popleft()
        x = cur[0]
        y = cur[1]
        for i in range(4):
            nx = x +dx[i]
            ny = y +dy[i]
            if nx<0 or nx>=n or ny < 0 or ny >=m:
                continue
            if board[nx][ny]==0 or ch[nx][ny]==1:
                continue
            ch[nx][ny]=1
            board[nx][ny] = board[x][y]+1
            q.append((nx,ny))

    return board[n-1][m-1]


n,m = map(int,input().split())
cnt = 0

dx = [-1,0,1,0]
dy = [0,1,0,-1]
board=[list(map(int,input())) for _ in range(n)]
ch=[[0]*m for _ in range(n)]
print(bfs(0,0))
import sys
from collections import deque
import heapq
import copy
input = sys.stdin.readline
#sys.stdin=open("input.txt", "rt")

n,m = map(int,input().split())
board=[]
tmp = [[0]*m for _ in range(n+1)]
for _ in range(n):
    board.append(list(map(int,input().split())))
res = -2147000000
dx = [-1,0,1,0]
dy = [0,1,0,-1]
def count_score():
    score = 0
    for i in range(n):
        for j in range(m):
            if tmp[i][j]==0:
                score+=1
    return score

def virus(x,y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny <m:
            if tmp[nx][ny]==0:
                tmp[nx][ny]=2
                virus(nx,ny)
        
def dfs(cnt):
    global res
    if cnt == 3:
        for i in range(n):
            for j in range(m):
                tmp[i][j]=board[i][j]
                
        for i in range(n):
            for j in range(m):
                if tmp[i][j]==2:
                    virus(i,j)

        res = max(res,count_score())
        return
    for i in range(n):
        for j in range(m):
            if board[i][j]==0:
                board[i][j]=1
                cnt+=1
                dfs(cnt)
                board[i][j]=0
                cnt-=1

dfs(0)
print(res)
'''
미로의 최단거리 통로
'''
import sys
from collections import deque
sys.stdin=open("input.txt", "r")

if __name__=="__main__":
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    board=[list(map(int,input().split())) for _ in range(7)]
    dis=[[0]*7 for _ in range(7)]
    q=deque()
    q.append((0,0))
    board[0][0]=1
    while q:
        cur = q.popleft()
        x = cur[0]
        y = cur[1]
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx < 0 or ny < 0 or nx >= 7 or ny >=7 :
                continue
            if board[nx][ny] != 0:
                continue
            board[nx][ny]=1
            dis[nx][ny]=dis[x][y]+1
            q.append((nx,ny))
    if dis[6][6] == -1:
        print(-1)
    else:
        print(dis[6][6])
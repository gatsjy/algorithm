'''
게임 개발
'''
import sys
sys.stdin=open("input.txt", "r")

n,m = map(int,input().split())
x,y,direction = map(int,input().split())
board = [list(map(int,input().split())) for _ in range(n)]
ch = [[0]*m for _ in range(n)]

def leftTurn():
    global direction
    direction -= 1
    if direction == -1:
        direction = 3

# 북, 동, 남, 서
dx = [-1,0,1,0]
dy = [0,1,0,-1]
res = 0
endcnt = 0
while True:
    leftTurn()
    nx = x + dx[direction]
    ny = y + dx[direction]
    if board[nx][ny]==0 and ch[nx][ny]==0:
        x = nx
        y = ny
        res +=1
        endcnt = 0
        ch[nx][ny]=1
        continue
    else:
        endcnt+=1

    if endcnt==4:
        nx = x - dx[direction]
        ny = y - dy[direction]
        if board[nx][ny]==1 or ch[nx][ny]==1:
            break
        else:
            x = nx
            y = ny
print(res)
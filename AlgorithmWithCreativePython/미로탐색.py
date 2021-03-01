'''
¹Ì·ÎÅ½»ö(DFS)
'''
import sys
from collections import deque
#sys.stdin = open("input.txt", "r")

def dfs(x, y) :
    global cnt
    if x == 6 and y == 6 :
        cnt += 1
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx <= 6 and 0 <= ny <= 6 and board[nx][ny] == 0 :
                board[nx][ny] = 1
                dfs(nx, ny)
                board[nx][ny] = 0


if __name__ == "__main__":
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    board = [list(map(int, input().split())) for _ in range(7)]
    board[0][0] = 1
    cnt = 0
    dfs(0, 0)
    print(cnt)
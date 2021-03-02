'''
단지번호붙이기(DFS)
'''
import sys
from collections import deque
#sys.stdin = open("input.txt", "r")

def dfs(x, y) :
    global cnt
    board[x][y] = 0
    for i in range(4) :
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < nand board[nx][ny] == 1 :
            dfs(nx, ny)
            cnt += 1


            if __name__ == "__main__" :
                dx = [1, 0, -1, 0]
                dy = [0, 1, 0, -1]
                n = int(input())
                board = [list(map(int, input())) for _ in range(n)]
                res = []
                for i in range(n) :
                    for j in range(n) :
                        if board[i][j] == 1 :
                            cnt = 1
                            dfs(i, j)
                            res.append(cnt)
                            res.sort()

                            print(len(res))
                            for x in res :
print(x)
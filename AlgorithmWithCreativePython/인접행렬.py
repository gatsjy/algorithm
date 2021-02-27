'''
인접행렬(가중치 방향그래프)
'''
import sys
#sys.stdin=open("input.txt", "r")

if __name__=="__main__":
    n,m = map(int,input().split())
    board=[[0]*(n+1) for _ in range(n+1)]

    for i in range(m):
        a,b,c = map(int,input().split())
        board[a-1][b-1]=c

    for i in range(n):
        for j in range(n):
            print(board[i][j], end=' ')
        print()

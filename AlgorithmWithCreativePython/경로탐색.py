''''
°æ·ÎÅ½»ö
'''
import sys
#sys.stdin = open("input.txt", "r")

def dfs(L) :
    global cnt
    if L == n :
        cnt += 1
        return
    else :
        for i in range(1, n + 1) :
            if board[L][i] == 1 :
                next = i
                if ch[next] == 0 :
                    ch[next] = 1
                    a.append(i)
                    dfs(next)
                    ch[next] = 0
                    a.pop()

                    if __name__ == "__main__":
n, m = map(int, input().split())
board = [[0]* (n + 1) for _ in range(n + 1)]
for _ in range(m) :
    a, b = map(int, input().split())
    board[a][b] = 1
    cnt = 0
    a = [1]
    ch = [0] * (n + 1)
    ch[1] = 1
    dfs(1)
    print(cnt)
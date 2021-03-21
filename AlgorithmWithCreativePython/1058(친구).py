import sys
sys.stdin=open("input.txt","r")
INF = int(1e9)
n = int(input())
board = [list(input()) for _ in range(n)]
ch = [[INF]*n for _ in range(n)]

for a in range(n):
    for b in range(n):
        if a==b:
            ch[a][b]=0

for a in range(n):
    for b in range(n):
        if board[a][b]=='Y':
            ch[a][b]=1
            
for k in range(n):
    for a in range(n):
        for b in range(n):
            if a==b:continue
            if board[a][k]=='Y' and board[k][b]=='Y':
                ch[a][b]=1
                
res = -INF
for a in range(n):
    tmp = 0
    for b in range(n):
        if a==b:continue
        if ch[a][b]==1:
            tmp+=1
    res = max(res,tmp)

print(res)
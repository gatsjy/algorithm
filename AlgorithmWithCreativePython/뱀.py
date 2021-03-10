import sys
from collections import defaultdict
from collections import deque
input = sys.stdin.readline
#sys.stdin=open("input.txt","r")
N = int(input())
board=[[0]*(N) for _ in range(N)]
n = int(input())
# 사과 자리 세팅하기
for _ in range(n):
    a,b=map(int,input().split())
    board[a-1][b-1]=1
# 방향전환 세팅하기
n = int(input())
spins=deque()
for _ in range(n):
    ins = list(input().split())
    spins.append((int(ins[0]),ins[1]))
# 시뮬레이션 시작
direction = 0 # 동에서 부터 시작
dir=[[0,1],[1,0],[0,-1],[-1,0]] # 각각 동 남 서 북
x,y = 0,0
snakes=deque() # 뱀의 몸통을 나타내는 함수
snakes.append((0,0))
time = 0 # 시간초시작

# 게임이 끝나는지 확인하는 함수
def isEnd(snakes):
    global x,y
    if x < 0 or x >= N or y < 0 or y >=N :
        return False
    for snake in snakes:
         if x == snake[0] and y == snake[1]:
            return False
    return True

# 로테이션 되어야 하는지 확인하는 함수
def isSpins(spins,time):
    global direction
    if spins:
        if spins[0][0]==time:
            # 시계방향으로 돌기
            if spins[0][1]=='D':
                if direction==3:
                    direction=0
                else:
                    direction+=1
            else:
                if direction==0:
                    direction=3
                else:
                    direction-=1
            spins.popleft()

# 한칸 앞으로 움직이는 함수
def takeMove(board,direction,snakes):
    global x,y
    snakes.append((x,y))
    #한칸 앞이 사과일 때
    if board[x][y]==1:
        board[x][y]=0
    else:
        snakes.popleft()
    
                
while True:
    x=dir[direction][0]+x
    y=dir[direction][1]+y
    time+=1
    if not isEnd(snakes) :
        print(time)
        break
    isSpins(spins,time)
    takeMove(board,direction,snakes)
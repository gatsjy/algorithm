import sys
from collections import defaultdict
from collections import deque
input = sys.stdin.readline
#sys.stdin=open("input.txt","r")
N = int(input())
board=[[0]*(N) for _ in range(N)]
n = int(input())
# ��� �ڸ� �����ϱ�
for _ in range(n):
    a,b=map(int,input().split())
    board[a-1][b-1]=1
# ������ȯ �����ϱ�
n = int(input())
spins=deque()
for _ in range(n):
    ins = list(input().split())
    spins.append((int(ins[0]),ins[1]))
# �ùķ��̼� ����
direction = 0 # ������ ���� ����
dir=[[0,1],[1,0],[0,-1],[-1,0]] # ���� �� �� �� ��
x,y = 0,0
snakes=deque() # ���� ������ ��Ÿ���� �Լ�
snakes.append((0,0))
time = 0 # �ð��ʽ���

# ������ �������� Ȯ���ϴ� �Լ�
def isEnd(snakes):
    global x,y
    if x < 0 or x >= N or y < 0 or y >=N :
        return False
    for snake in snakes:
         if x == snake[0] and y == snake[1]:
            return False
    return True

# �����̼� �Ǿ�� �ϴ��� Ȯ���ϴ� �Լ�
def isSpins(spins,time):
    global direction
    if spins:
        if spins[0][0]==time:
            # �ð�������� ����
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

# ��ĭ ������ �����̴� �Լ�
def takeMove(board,direction,snakes):
    global x,y
    snakes.append((x,y))
    #��ĭ ���� ����� ��
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
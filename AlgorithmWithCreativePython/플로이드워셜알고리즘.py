'''
�ִܰ�� �÷��̵� ���� �˰���
'''
import sys
sys.stdin=open("input.txt", "rt")
INF = int(1e9)

n = int(input())
m = int(input())
graph = [[INF]*(n+1) for _ in range(n+1)]

# �ڱ� �ڽ����� ���� ����� �ʱ�ȭ
for a in range(1,n+1):
    for b in range(1,n+1):
        if a==b:
            graph[a][b]=0

# �� ������ ���� ������ �Է¹޾�, �� ������ �ʱ�ȭ
for _ in range(m):
    # A���� B�� ���� ����� C��� ����
    a,b,c=map(int,input().split())
    graph[a][b]=c

# ��ȭ�Ŀ� ���� �÷��̵� ���� �˰��� ����
for k in range(1,n+1):
    for a in range(1,n+1):
        for b in range(1,n+1):
            graph[a][b]=min(graph[a][b],graph[a][k]+graph[k][b])

for a in range(1,n+1):
    for b in range(1,n+1):
        if graph[a][b]==INF:
            print("INF", end=' ')
        else:
            print(graph[a][b], end=' ')
    print()
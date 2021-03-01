'''
ť ����
'''
import sys
sys.stdin=open("input.txt", "r")
from collections import deque

#dfs �޼��� ����
def dfs(graph, v, visited):
    # ���� ��带 �湮ó��
    visited[v] = True
    print(v, end=' ')
    for x in graph[v]:
        if visited[x] ==False:
            dfs(graph, x, visited)

#bfs �޼��� ����
def bfs(graph, start, visited):
    queue = deque([start])
    # ���� ��带 �湮 ó��
    visited[start] = True
    # ť�� �������� ó��
    while queue:
        cur = queue.popleft()
        print(cur, end=' ')
        for x in graph[cur]:
            if not visited[x]:
                queue.append(x)
                visited[x]=True



graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

# �� ��尡 �湮�� ������ ����Ʈ �ڷ������� ǥ��(1���� ����Ʈ)
visited = [False]*9

# ���ǵ� DFS �Լ� ȣ��
#dfs(graph, 1, visited)
bfs(graph,1,visited)
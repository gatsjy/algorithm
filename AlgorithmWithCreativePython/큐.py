'''
큐 예제
'''
import sys
sys.stdin=open("input.txt", "r")
from collections import deque

#dfs 메서드 구현
def dfs(graph, v, visited):
    # 현재 노드를 방문처리
    visited[v] = True
    print(v, end=' ')
    for x in graph[v]:
        if visited[x] ==False:
            dfs(graph, x, visited)

#bfs 메서드 구현
def bfs(graph, start, visited):
    queue = deque([start])
    # 현재 노드를 방문 처리
    visited[start] = True
    # 큐가 빌때까지 처리
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

# 각 노드가 방문된 정보를 리스트 자료형으로 표현(1차원 리스트)
visited = [False]*9

# 정의된 DFS 함수 호출
#dfs(graph, 1, visited)
bfs(graph,1,visited)
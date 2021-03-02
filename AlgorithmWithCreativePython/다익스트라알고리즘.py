'''
다익스트라 알고리즘 정
'''
import sys
sys.stdin = open("input.txt", "rt")
INF = int(1e9)

# 노드의 개수, 간선의 개수 입력받기
n, m = map(int, input().split())
# 시작 노드 번호를 입력받기
start = int(input())
# 각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트 만들기
graph = [[]for i in range(n + 1)]
# 방문한 적이 있는지 체크하는 목적의 리스트 만들기
visited = [False] * (n + 1)
# 최단 거리 테이블을 모두 무한으로 초기화
distance = [INF] * (n + 1)


# 모든 간선 정보를 입력받기
for _ in range(m) :
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

    #방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환
    def get_smallest_node() :
    min_value = INF
    index = 0
    for i in range(1, n + 1) :
        if distance[i] < min_valueand visited[i] == False :
            idx = i
            min_value = distance[i]
            return index

            def dijkstra(start) :
            visited[start] = True
            distance[start] = 0
            for x in graph[start] :
                distance[x[0]] = x[1] # 일단 시작점부터 세팅 시작
                # 시작점을 제외한 n개의 노드를 순회
                for i in range(n - 1) :
                    now = get_smallest_node()
                    visited[now] = True
                    for j in graph[now] :
                        cost = distance[now] + j[1]
                        if cost < distance[j[0]] :
                            distance[j[0]] = cost

                            dijkstra(start)
                            for x in distance :
print(x)
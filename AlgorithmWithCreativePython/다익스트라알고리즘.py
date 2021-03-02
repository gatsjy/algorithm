'''
���ͽ�Ʈ�� �˰��� ��
'''
import sys
sys.stdin = open("input.txt", "rt")
INF = int(1e9)

# ����� ����, ������ ���� �Է¹ޱ�
n, m = map(int, input().split())
# ���� ��� ��ȣ�� �Է¹ޱ�
start = int(input())
# �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� ����Ʈ �����
graph = [[]for i in range(n + 1)]
# �湮�� ���� �ִ��� üũ�ϴ� ������ ����Ʈ �����
visited = [False] * (n + 1)
# �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
distance = [INF] * (n + 1)


# ��� ���� ������ �Է¹ޱ�
for _ in range(m) :
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

    #�湮���� ���� ��� �߿���, ���� �ִ� �Ÿ��� ª�� ����� ��ȣ�� ��ȯ
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
                distance[x[0]] = x[1] # �ϴ� ���������� ���� ����
                # �������� ������ n���� ��带 ��ȸ
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
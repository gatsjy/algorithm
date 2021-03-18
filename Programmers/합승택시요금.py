def solution(n, s, a, b, fares):
    answer = 0
    INF = int(1e9)
    graph = [[INF] * (n+1) for _ in range(n+1)]
    for fare in fares:
        graph[fare[0]][fare[1]]=fare[2]
        graph[fare[1]][fare[0]]=fare[2]
    
    for x in range(1,n+1):
        for y in range(1,n+1):
            if x==y:
                graph[x][y]=0
    
    for k in range(1,n+1):
        for x in range(1,n+1):
            for y in range(1,n+1):
                graph[x][y] = min(graph[x][y],graph[x][k]+graph[k][y])
    
    answer = graph[s][a] + graph[s][b]
    for k in range(1,n+1):
        if graph[s][k] == INF or graph[k][a] == INF or graph[k][b] == INF : continue
        answer = min(answer, graph[s][k] + graph[k][a] + graph[k][b])
    return answer
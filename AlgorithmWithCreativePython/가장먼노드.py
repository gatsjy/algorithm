import heapq

def solution(n, edge):
    answer = 0
    INF = int(1e9)
    graph=[[]*(n+1) for _ in range(n+1)]
    
    # 그래프를 입력 받는다
    for edg in edge:
        graph[edg[0]].append((edg[1],1))
        graph[edg[1]].append((edg[0],1))
    
    distance=[INF]*(n+1)
    q=[]
    distance[1]=0
    heapq.heappush(q,(0,1))
    while q:
        dist,now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist+i[1]
            if cost < distance[i[0]]:
                distance[i[0]]=cost
                heapq.heappush(q,(cost,i[0]))
    max_value = max(distance[1:])
    answer = distance.count(max_value)
    return answer
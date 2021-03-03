'''
Àüº¸
'''
import sys
import heapq
sys.stdin=open("input.txt", "rt")
INF = int(1e9)

n,m,c = map(int,input().split())
graph=[[] for _ in range(n+1)]
distance=[INF]*(n+1)
for m in range(m):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))

def dikstra(start):
    q=[]
    heapq.heappush(q,(0,start))
    distance[start]=0
    while q:
        dist,now=heapq.heappop(q)
        print(dist,now)
        if distance[now]<dist:
            continue
        for i in graph[now]:
            cost = dist+i[1]
            if distance[i[0]]>cost:
                print(distance)
                distance[i[0]]=cost
                heapq.heappush(q,(cost,i[0]))

print(graph)
dikstra(c)
print(distance)
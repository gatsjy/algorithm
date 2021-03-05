import sys
from collections import deque
input = sys.stdin.readline
#sys.stdin=open("input.txt", "r")

n,m=map(int,input().split())

indegree = [0]*(n+1)

graph=[[]*(n+1) for _ in range(n+1)]

for i in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    indegree[b]+=1

def topology_sort():
    res = [0]*(n+1)
    q=deque()
    for i in range(1,n+1):
        if indegree[i]==0:
            q.append(i)

    while q:
        now = q.popleft()
        for i in graph[now]:
            indegree[i]-=1
            res[i] = max(res[i],res[now]+1)
            if indegree[i]==0:
                q.append(i)

    for i in range(1,n+1):
        print(res[i]+1, end= ' ')
topology_sort()
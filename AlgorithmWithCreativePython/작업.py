import sys
from collections import deque
import copy
input = sys.stdin.readline
#sys.stdin=open("input.txt", "r")

n = int(input())

indegree=[0]*(n+1)
time=[0]*(n+1)
graph=[[]*(n+1) for _ in range(n+1)]
for i in range(1,n+1):
    ins = list(map(int,input().split()))
    time[i]=ins[0]
    for j in range(ins[1]):
        graph[ins[j+2]].append(i)
        indegree[i]+=1

def topology_sort():
    res = copy.deepcopy(time)
    q = deque()
    for i in range(1,n+1):
        if indegree[i]==0:
            q.append(i)

    while q:
        now = q.popleft()
        for i in graph[now]:
            indegree[i] -=1
            res[i] = max(res[i], res[now]+time[i])
            if indegree[i] == 0:
                q.append(i)

    print(max(res))
topology_sort()        
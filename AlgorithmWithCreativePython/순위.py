INF = int(1e9)
graph = [[INF]*26 for _ in range(26)]
 
n = int(input())
 
for _ in range(n):
	a,b,c = input().split()
	a = a.split()[0]
	c = c.split()[0]
	graph[ord(a)-97][ord(c)-97]=1
 
for a in range(26):
	for b in range(26):
		if a==b:
			graph[a][b]=0
 
for k in range(26):
	for a in range(26):
		for b in range(26):
			graph[a][b]=min(graph[a][b], graph[a][k]+graph[k][b])
 
n = int(input())
 
for _ in range(n):
	a,b,c = input().split()
	a = a.split()[0]
	c = c.split()[0]
	if graph[ord(a)-97][ord(c)-97] == INF:
		print("F")
	else:
		print("T")
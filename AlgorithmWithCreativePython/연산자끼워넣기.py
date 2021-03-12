n = int(input())
a = list(map(int,input().split()))
op = list(map(int,input().split())) # 연산자를 담을 리스트(더하기,빼기,곱하기,나누기)
 
min_value = int(1e9)
max_value = -int(1e9)

def dfs(L,sum):
	global min_value,max_value
	if L == n:
		min_value=min(min_value,sum)
		max_value=max(max_value,sum)
	else:
		if op[0] > 0:
			op[0]-=1
			dfs(L+1,sum+a[L])
			op[0]+=1
		if op[1] > 0:
			op[1]-=1
			dfs(L+1,sum-a[L])
			op[1]+=1
		if op[2] > 0:
			op[2]-=1
			dfs(L+1,sum*a[L])
			op[2]+=1
		if op[3] > 0:
			op[3]-=1
			dfs(L+1,int(sum/a[L])) # 다음과 같이 하여 나머지를 없애준다.
			op[3]+=1
 
dfs(1,a[0])
print(max_value)
print(min_value)
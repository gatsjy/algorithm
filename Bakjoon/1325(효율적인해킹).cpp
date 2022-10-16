#include <bits/stdc++.h>

using namespace std;

int visited[104];
vector<int> v[104];
int n, m,a,b;
int mx;
int dp[104];
int dfs(int here) {
	int ret = 1;
	visited[here] = 1;
	for (int there : v[here]) {
		if (visited[there]) continue;
		ret += dfs(there);
	}
	return ret;
}
int main() {
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		dp[i] = dfs(i);
		mx = max(dp[i], mx);
	}
	for (int i = 1; i <= n; i++) if (mx == dp[i]) cout << i << " ";
	return 0;
}
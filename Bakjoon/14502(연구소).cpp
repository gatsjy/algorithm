#include <bits/stdc++.h>

using namespace std;

int n, m;
int vis[10][10];
int a[10][10];
vector<pair<int, int>> v;
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
void dfs(int x, int y) {
	if (a[x][y] == 1 || vis[x][y]) return;
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		dfs(nx, ny);
	}
}
int solve() {
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2) dfs(i, j);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && a[i][j] == 0)ans++;
		}
	}
	return ans;
}
int main() {

	// 1. 무식? 벽을 세우는 모든 경우의수를 확인한다..
	// 2. 효율? 무식하게 되는지 안되는지 확인? 범위를 확인해야 합니다.
	// 64c3 36600 -> 충분히 계산할 수 있다. 1억이나 10억 이상... 

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (!a[i][j]) v.push_back({ i,j }); // 벽을 세우는 후보들
		}
	}

	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
				ans = max(ans, solve());
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
			}
		}
	}

	cout << ans;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int n, m, res;
int vis[10][10];
int a[10][10];
vector<pair<int,int>> v;

void dfs(int y, int x) {
	if (a[y][x] == 1 || vis[y][x]) return;
	vis[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= n || nx >= m || ny < 0 || nx < 0) continue;
			dfs(ny, nx);
		}
	}
}

int solve() {
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2) dfs(i, j);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 0 && a[i][j]==0) cnt++;
		}
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) v.push_back({ i,j });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				//cout << i << " " << j << " " << k << "\n";
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
				res = max(res,solve());
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
			}
		}
	}
	cout << res;

	return 0;
}
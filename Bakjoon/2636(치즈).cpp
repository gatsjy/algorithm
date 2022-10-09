#include <bits/stdc++.h>

using namespace std;

int visited[101][101];
int a[101][101];
int n, m;
vector<pair<int, int>> v;
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};

void dfs(int y, int x) {
	visited[y][x] = 1;
	if (a[y][x] == 1) {
		v.push_back({ y,x });
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || ny >= n || nx < 0  || nx >= m || visited[ny][nx]) continue;
		dfs(ny, nx);
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int cnt = 0;
	int cnt2 = 0;

	while (true) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		v.clear();
		dfs(0, 0);
		cnt2 = 0;
		for (int i = 0; i < v.size(); i++) {
			a[v[i].first][v[i].second] = 0;
			cnt2++;
		}
		cnt++;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) {
					flag = false;
				}
			}
		}
		if (flag) break;
	}

	cout << cnt << "\n" << cnt2;

	return 0;
}
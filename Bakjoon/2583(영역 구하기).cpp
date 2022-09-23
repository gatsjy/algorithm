#include <bits/stdc++.h>

using namespace std;

int m, n, k;
int d;
int cnt;
int a[101][101], visited[101][101];
vector<int> res;

int yy2, yy1, xx2, xx1;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void dfs(int y, int x) {
	visited[y][x] = 1;
	cnt += 1;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (!visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> m >> n >> k;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 1;
		}
	}

	for (int d = 0; d < k; d++) {
		// y1, x1 -> 왼쪽아래
		// y2, x2 -> 오른쪽위
		//cin >> yy1 >> xx1 >> yy2 >> xx2;
		cin >> xx1 >> yy1 >> xx2 >> yy2;

		for (int i = yy1; i < yy2; i++) {
			for (int j = xx1; j < xx2; j++) {
				visited[j][i] = 1;
			}
		}
	}

	// 근데 상관 없잖어..?
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				res.push_back(cnt);
			}
		}
	}
	return 0;
}
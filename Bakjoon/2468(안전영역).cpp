#include <bits/stdc++.h>

using namespace std;

int n; // n은 2이상 100이하의 정수
int visited[101][101], a[101][101];
int ret = 1;
int x, y;
int dy[4] = {-1,0,1,0};
int dx[4] = { 0,1,0,-1 };

void dfs(int y, int x, int d) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (!visited[ny][nx] && a[ny][nx] > d) {
			dfs(ny, nx, d);
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int d = 1; d < 101; d++) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > d && !visited[i][j]) {
					dfs(i, j, d);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
	}

	cout << ret << "\n";


	return 0;
}
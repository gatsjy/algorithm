#include<bits/stdc++.h>

using namespace std;

namespace 미로영역_2468 {
	int dy[4] = { -1,0,1,0 };
	int dx[4] = { 0,1,0,-1 };
	int visited[101][101], b[101][101], e[101][101], res = 1, n;
	void dfs(int y, int x) {
		visited[y][x] = 1;
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (!visited[ny][nx] && e[ny][nx] == 0) dfs(ny, nx);
		}
		return;
	}
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> b[i][j];
			}
		}

		for (int d = 1; d <= 101; d++) {
			fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
			int tmp = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (e[i][j] == 1) continue;
					if (b[i][j] <= d) e[i][j] = 1;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (e[i][j] == 0 && !visited[i][j]) {
						dfs(i, j);
						tmp++;
					}
				}
			}
			res = max(res, tmp);
		}
		cout << res << '\n';
		return 0;
	}
}

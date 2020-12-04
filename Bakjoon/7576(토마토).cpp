#include <bits/stdc++.h>

using namespace std;

namespace _7576 {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int board[502][502];
	int dist[502][502];
	int m, n; // m 가로 , n 세로
	int main() {
		// 입력을 세로 가로로 받는다.
		cin >> m >> n;
		queue<pair<int, int>> q;
		// 세로 가로
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				if (board[i][j] == 0) {
					dist[i][j] = -1;
				}
				if (board[i][j] == 1) {
					q.push({ i,j });
				}
			}
		}
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || nx >= m) continue;
				if (dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				q.push({ nx,ny });
			}
		}
		int day = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dist[i][j] == -1) {
					cout << -1;
					return 0;
				}
			}
		}
		return 0;
	}
}
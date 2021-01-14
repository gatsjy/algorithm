#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

namespace _2589 {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	char board[51][51];
	int ch[51][51];
	int n, m;
	int res = -1;

	int bfs(int fx, int fy) {
		memset(ch, 0, sizeof(ch));
		int result = 0;
		queue<pair<int, int>> q;
		q.push({ fx,fy });
		ch[fx][fy] = 1;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			int x = cur.first;
			int y = cur.second;
			result = max(result, ch[x][y]);
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (board[nx][ny] == 'W' || ch[nx][ny] > 0) continue;
				ch[nx][ny] = ch[x][y] + 1;
				q.push({ nx,ny });
			}
		}
		return result - 1;
	}

	int main() {

		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char input;
				cin >> input;
				board[i][j] = input;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'L') {
					res = max(res, bfs(i, j));
				}
			}
		}

		cout << res;

		return 0;
	}
}
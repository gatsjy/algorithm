#include <iostream>
#include <string>

using namespace std;

namespace _17090 {
	// u, r, d, l
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int n, m;

	int dp[501][501];
	int board[501][501];

	int dfs(int x, int y, int dir) {
		if (dp[x][y] == 0)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) return dp[nx][ny] = 1;
			dp[x][y] = -1;
			return dp[x][y] = dfs(nx, ny, board[nx][ny]);
		}
		else {
			return dp[x][y];
		}
	}

	int main() {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				if (s[j] == 'U') {
					board[i][j] = 0;
				}
				else if (s[j] == 'R') {
					board[i][j] = 1;
				}
				else if (s[j] == 'D') {
					board[i][j] = 2;
				}
				else if (s[j] == 'L') {
					board[i][j] = 3;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[i][j] == 0) {
					dp[i][j] = dfs(i, j, board[i][j]);
				}
			}
		}

		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[i][j] == 1) {
					res++;
				}
			}
		}
		cout << res;
		return 0;
	}
}
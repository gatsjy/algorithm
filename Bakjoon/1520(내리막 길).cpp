#include <bits/stdc++.h>

using namespace std;

namespace _1520 {
	int m, n;
	int board[502][502];
	int dp[502][502];
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	int dfs(int x, int y) {
		if (x == m - 1 && y == n - 1) {
			return 1;
		}
		// dp[x][y]가 한번도 방문된 적이 없다면?
		else if (dp[x][y] == -1) {
			// 방문 체크를 함과 동시에 0으로 초기화
			dp[x][y] = 0;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
				if (board[xx][yy] >= board[x][y]) continue;
				dp[x][y] += dfs(xx, yy);
			}
		}
		// 방문을 한 경우라면 방문했을 당시 dp 리턴
		return dp[x][y];
	}

	int main() {
		cin >> m >> n;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				dp[i][j] = -1;
			}
		}

		dfs(0, 0);

		cout << dp[0][0];
		return 0;
	}
}
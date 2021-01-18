#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

namespace _11048 {
	int n, m;

	int board[1001][1001];
	int dp[1001][1001];

	int main() {

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
			}
		}

		dp[0][0] = board[0][0];
		// 맨 위쪽 채우기
		for (int i = 1; i < m; i++) {
			dp[0][i] = dp[0][i - 1] + board[0][i];
		}

		// 맨 왼쪽 채우기
		for (int i = 1; i < n; i++) {
			dp[i][0] = dp[i - 1][0] + board[i][0];
		}

		// dp 시작
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				dp[i][j] = max(dp[i - 1][j] + board[i][j], dp[i][j - 1] + board[i][j]);
			}
		}

		cout << dp[n - 1][m - 1];

		return 0;
	}
}
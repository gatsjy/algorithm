#include <iostream>
#include <algorithm>

using namespace std;

namespace _11660 {
	long long dp[1025][1025];
	long long board[1025][1025];
	int n, c;

	int main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n >> c;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> board[i][j];
				dp[i][j] = dp[i][j - 1] + board[i][j];
			}
		}

		while (c--) {
			int res = 0;
			int sx, sy, ex, ey;
			cin >> sx >> sy >> ex >> ey;
			for (int i = sx; i <= ex; i++) {
				res += dp[i][ey] - dp[i][sy - 1];
			}
			cout << res << "\n";
		}
		return 0;
	}
}
#include <bits/stdc++.h>

using namespace std;

namespace _12865 {
	int n, k;
	int dp[101][100001];
	vector<pair<int, int>> item;

	//4 8
	//6 13
	//4 8
	//4 6
	//5 12

	int main() {
		cin >> n >> k;
		item.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			int w, v;
			cin >> item[i].first >> item[i].second;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j >= item[i].first) {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i].first] + item[i].second);
				}
			}
		}

		cout << dp[n][k];
		return 0;
	}
}
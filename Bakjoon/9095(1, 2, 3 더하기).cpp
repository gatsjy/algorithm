#include <bits/stdc++.h>

using namespace std;

namespace _9095 {
	int dp[12] = { 0,1 };
	int main() {
		// 1,2,3
		dp[2] = dp[1] + 1;
		dp[3] = dp[2] + dp[1] + 1;
		for (int i = 4; i <= 12; i++) {
			dp[i] = dp[i - 2] + dp[i - 1] + dp[i - 3];
		}
		int c, n;
		cin >> c;
		while (c--) {
			cin >> n;
			cout << dp[n] << "\n";
		}
		return 0;
	}
}
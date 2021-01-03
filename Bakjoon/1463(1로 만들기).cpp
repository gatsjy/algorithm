#include <bits/stdc++.h>

using namespace std;
namespace _1463 {
	int dp[1000001] = { 0,0,1, };
	int n;

	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + 1;
			if (i % 3 == 0) {
				dp[i] = min(dp[i], dp[i / 3] + 1);
			}
			if (i % 2 == 0) {
				dp[i] = min(dp[i], dp[i / 2] + 1);
			}
		}
		cout << dp[n];
		return 0;
	}
}
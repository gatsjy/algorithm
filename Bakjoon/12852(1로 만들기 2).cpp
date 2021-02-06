#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dp(1000001);
int n;
int main() {
	cin >> n;
	dp[0] = { 0,0 };
	dp[1] = { 0,0 };
	for (int i = 2; i <= n; i++) {
		dp[i] = { dp[i - 1].first+1, i-1 };
		if (i % 3 == 0) {
			if (dp[i].first > dp[i / 3].first+1) {
				dp[i] = { dp[i / 3].first+1, i / 3 };
			}
		}
		if (i % 2 == 0) {
			if (dp[i].first > dp[i / 2].first + 1) {
				dp[i] = { dp[i / 2].first + 1, i / 2 };
			}
		}
	}
	cout << dp[n].first << "\n";
	while (n > 0) {
		cout << n << " ";
		n = dp[n].second;
	}
	return 0;
}
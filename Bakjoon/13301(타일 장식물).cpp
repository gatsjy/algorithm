#include <bits/stdc++.h>

using namespace std;

namespace _13301 {
	long long a[81];
	long long dp[81] = { 0,4,6,10,16 };

	int n;

	int main() {
		cin >> n;
		for (int i = 5; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		cout << dp[n];
		return 0;
	}
}
#include <bits/stdc++.h>

using namespace std;

namespace _2579 {
	int dp[301];
	int a[301];
	int n;
	int main() {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dp[1] = a[1];
		dp[2] = a[1] + a[2];
		for (int i = 3; i <= n; i++) {
			// 답답하면 내가 직접해보면 된다!!
			dp[i] = max(a[i] + a[i - 1] + dp[i - 3], a[i] + dp[i - 2]);
		}
		cout << dp[n];
		return 0;
	}
}

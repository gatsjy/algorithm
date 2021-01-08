#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

namespace _4097 {
	long long dp[250001];
	long long a[250001];

	int n;
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		while (1) {
			cin >> n;
			if (n == 0) {
				break;
			}
			memset(dp, 0, sizeof(dp));
			memset(a, 0, sizeof(a));

			for (int i = 0; i < n; i++) {
				cin >> a[i];
			}
			dp[0] = a[0];
			long long res = a[0];
			for (int i = 1; i < n; i++) {
				if (dp[i - 1] < 0) {
					dp[i] = a[i];
				}
				else {
					dp[i] = dp[i - 1] + a[i];
				}
				res = max(res, dp[i]);
			}
			cout << res << "\n";
		}
		return 0;
	}
}
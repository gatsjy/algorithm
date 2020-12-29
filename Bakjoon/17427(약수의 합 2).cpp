#include <bits/stdc++.h>

using namespace std;

namespace _17427 {
	long long dp[1000001];
	long long sum[1000001];

	int c, n;
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		for (int i = 1; i <= 1000000; i++) {
			for (int j = 1; i * j <= 1000000; j++) {
				dp[i * j] += i;
			}
			sum[i] = sum[i - 1] + dp[i];
		}

		cin >> c;
		while (c--) {
			cin >> n;
			cout << sum[n] << "\n";
		}
		return 0;
	}
}
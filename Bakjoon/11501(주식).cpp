#include <bits/stdc++.h>

using namespace std;

int c, n;

long price[1000001];
long dp[1000001];

int main(void) {
	cin >> c;
	while (c--) {
		cin >> n;
		memset(price, 0, sizeof(price));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			cin >> price[i];
		}

		int max_price = price[n - 1];
		for (int i = n - 1; i >= 0; i--) {
			if (max_price > price[i]) {
				dp[i] = max_price;
			}
			else {
				dp[i] = price[i];
				max_price = dp[i];
			}
		}

		long sum = 0;
		for (int i = 0; i < n; i++) {
			if (dp[i] > price[i]) {
				sum += dp[i] - price[i];
			}
		}

		cout << sum << "\n";
	}
	return 0;
}
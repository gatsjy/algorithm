#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
ll dp[101][21] = {};
ll a[101];
int n;
void solve(int n) {

	for (int i = 0; i <= 20; i++) {

		if (dp[n - 1][i]) {

			// +계산
			if (i + a[n] <= 20) {
				dp[n][i + a[n]] += dp[n - 1][i];
			}

			// -계산
			if (i - a[n] >= 0) {
				dp[n][i - a[n]] += dp[n - 1][i];
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dp[1][a[1]] = 1;

	for (int i = 2; i < n; i++) {
		solve(i);
	}


	cout << dp[n - 1][a[n]];

	return 0;
}
#include <bits/stdc++.h>

using namespace std;
int dp[1001] = { 0,1,2 };
int mod = 10007;
int main() {

	int n;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}

	cout << dp[n];
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

namespace _1309 {
	int dp[100001][2] = { {0,0},{1,1},{2,2} };
	int sdp[100001] = { 0,2,6 };
	int n;
	int mod = 9901;
	int main() {
		cin >> n;
		for (int i = 3; i <= n; i++) {
			dp[i][0] = (dp[i - 1][1] + sdp[i - 2] + 1) % mod;
			dp[i][1] = (dp[i - 1][0] + sdp[i - 2] + 1) % mod;
			sdp[i] += (sdp[i - 1] + dp[i][1] + dp[i][0]) % mod;
		}

		cout << (sdp[n] + 1) % mod;

		return 0;
	}
}


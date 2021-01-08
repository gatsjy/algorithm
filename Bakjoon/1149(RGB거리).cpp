#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001][3];
int dp[1001][3];

// 키워드 최소, 색깔 3개(빨,초,파)
// dp[i][2] -> i번째 집을 칠할때 비용의 최솟값, 단 i번째 집은 파란색이다.
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
	}

	cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001][3];
int dp[1001][3];

// Ű���� �ּ�, ���� 3��(��,��,��)
// dp[i][2] -> i��° ���� ĥ�Ҷ� ����� �ּڰ�, �� i��° ���� �Ķ����̴�.
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
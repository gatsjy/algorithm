#include <bits/stdc++.h>

using namespace std;

namespace _��Ʈ��ũ_��_�ڸ���_bottom_up {
	int dp[50];
	int main() {
		int n;
		cin >> n;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		cout << dp[n];
		return 0;
	}
}

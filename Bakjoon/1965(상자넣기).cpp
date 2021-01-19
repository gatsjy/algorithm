#include <bits/stdc++.h>

using namespace std;

namespace _1965 {
	typedef long long ll;
	int n;
	ll a[1001];
	ll dp[1001];
	int res = 1;
	int main() {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			dp[i] = 1; // 최소값 1로 초기화
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; j >= 1; j--) {
				if (a[i] > a[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (res < dp[i]) res = dp[i];
		}

		cout << res;

		return 0;
	}
}
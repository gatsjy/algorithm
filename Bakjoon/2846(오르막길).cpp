#include <bits/stdc++.h>

using namespace std;
namespace _2846 {
	int n;
	vector<int> v;
	vector<int> dp;
	int main() {
		cin >> n;
		v.resize(n);
		dp.resize(n - 1);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (i != 0) {
				dp[i - 1] = v[i] - v[i - 1];
			}
		}

		int res = -1;
		int tmpsum = 0;
		for (int i = 0; i < dp.size(); i++) {
			if (dp[i] > 0) {
				tmpsum += dp[i];
			}
			else {
				if (res < tmpsum) res = tmpsum;
				tmpsum = 0;
			}
		}
		if (res < tmpsum) res = tmpsum;

		cout << res;
		return 0;
	}
}
#include <bits/stdc++.h>

using namespace std;

namespace _1208 {
	int n, s;
	vector<int> v;
	map<int, int> m;
	int half = 0;
	long long ans = 0;
	void dfsLeft(int idx, int sum) {
		if (idx == half) {
			m[sum]++;
			return;
		}
		dfsLeft(idx + 1, sum + v[idx]);
		dfsLeft(idx + 1, sum);
	}

	void dfsRight(int idx, int sum) {
		if (idx == n) {
			ans += m[s - sum];
			return;
		}
		dfsRight(idx + 1, sum + v[idx]);
		dfsRight(idx + 1, sum);
	}

	int main() {
		cin >> n >> s;
		v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		half = n / 2;
		dfsLeft(0, 0);
		dfsRight(half, 0);
		if (s == 0) ans--;
		cout << ans;
		return 0;
	}
}

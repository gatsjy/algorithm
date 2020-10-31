#include <bits/stdc++.h>

namespace _84 {
	using namespace std;

	int n;
	vector<int> day, cost;
	int res = -2147000000;
	void dfs(int d, int sum) {
		if (d == n + 1) {
			res = max(sum, res);
		}
		else {
			if (d + day[d] <= n + 1) dfs(d + day[d], sum + cost[d]);
			dfs(d + 1, sum);
		}
	}
	int main() {
		cin >> n;
		int a, b;
		day.push_back(0);
		cost.push_back(0);
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			day.push_back(a);
			cost.push_back(b);
		}
		dfs(1, 0);
		cout << res;
		return 0;
	}
}
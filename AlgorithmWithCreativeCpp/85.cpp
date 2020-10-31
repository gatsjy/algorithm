#include <bits/stdc++.h>

namespace _85 {
	using namespace std;
	int n;
	vector<int> a;
	vector<int> op(4);
	int resmax = -2147000000;
	int resmin = 2147000000;
	void dfs(int L, int sum) {
		if (L == n) {
			resmax = max(resmax, sum);
			resmin = min(resmin, sum);
		}
		else {
			if (op[0] > 0) {
				op[0]--;
				dfs(L + 1, sum + a[L]);
				op[0]++;
			}
			if (op[1] > 0) {
				op[1]--;
				dfs(L + 1, sum - a[L]);
				op[1]++;
			}
			if (op[2] > 0) {
				op[2]--;
				dfs(L + 1, sum * a[L]);
				op[2]++;
			}
			if (op[3] > 0) {
				op[3]--;
				dfs(L + 1, sum / a[L]);
				op[3]++;
			}
		}
	}
	int main() {
		cin >> n;
		a = vector<int>(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < 4; i++) {
			cin >> op[i];
		}
		dfs(1, a[0]);
		cout << resmax << endl;
		cout << resmin << endl;
		return 0;
	}
}
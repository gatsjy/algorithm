#include <bits/stdc++.h>

using namespace std;

namespace _15649 {
	int n, m;
	int a[10];
	int ch[10];

	void dfs(int level) {
		if (level == m) {
			for (int i = 0; i < m; i++) {
				cout << a[i] << " ";
			}
			cout << "\n";
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (!ch[i]) {
				a[level] = i;
				ch[i] = 1;
				dfs(level + 1);
				ch[i] = 0;
			}
		}
	}

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> n >> m;
		dfs(0);
		return 0;
	}
}

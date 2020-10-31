#include <bits/stdc++.h>

namespace _82 {
using namespace std;

	int n, m;
	int ch[30];
	int a[30];
	int res[30];

	void dfs(int x) {
		if (x == m) {
			for (int i = 0; i < m; i++) {
				cout << res[i] << " ";
			}
			cout << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (ch[i] == 0) {
					res[x] = a[i];
					ch[i] = 1;
					dfs(x + 1);
					ch[i] = 0;
				}
			}
		}
	}
	int main() {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		dfs(0);
		return 0;
	}
}
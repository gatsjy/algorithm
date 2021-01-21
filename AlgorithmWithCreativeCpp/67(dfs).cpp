#include <bits/stdc++.h>

using namespace std;

namespace _67{
	int a[30][30];
	int n, m;
	bool ch[30];
	int cost = 2147000000;
	void dfs(int v, int sum) {
		if (n == v) {
			cost = min(cost, sum);
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (a[v][i] > 0 && ch[i] == 0) {
					ch[v] = 1;
					dfs(i, sum + a[v][i]);
					ch[v] = 0;
				}
			}
		}
	}

	int main() {
		cin >> n >> m;
		int start, end, val;
		for (int i = 1; i <= m; i++) {
			cin >> start >> end >> val;
			a[start][end] = val;
		}
		ch[1] = 1;
		dfs(1, 0);
		cout << cost;
		return 0;
	}
}
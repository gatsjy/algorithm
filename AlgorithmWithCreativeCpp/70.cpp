#include <bits/stdc++.h>

using namespace std;

namespace _70 {
	int main() {
		queue<int> q;
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v(n + 1);
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			v[a].push_back(b);
		}

		int dist[21] = { 0, };
		bool ch[21] = { 0 };
		q.push(1);
		ch[1] = 1;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < v[cur].size(); i++) {
				if (ch[v[cur][i]] == 0) {
					ch[v[cur][i]] = 1;
					q.push(v[cur][i]);
					dist[v[cur][i]] = dist[cur] + 1;
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			cout << i << " : " << dist[i] << endl;
		}
		return 0;
	}
}

#include <bits/stdc++.h>

using namespace std;

namespace _1260 {
	int n, m, start;
	int graph[1001][1001];
	int ch[1001];

	int a, b;

	void dfs(int v) {
		cout << v << " ";
		ch[v] = 1;
		for (int i = 1; i <= n; i++) {
			if (graph[v][i] == 1 && ch[i] == 0) {
				dfs(i);
			}
		}
	}

	void bfs(int v) {
		queue<int> q;
		q.push(v);
		ch[v] = 1;
		while (!q.empty()) {
			int cur = q.front();
			cout << cur << " ";
			q.pop();
			for (int i = 1; i <= n; i++) {
				if (graph[cur][i] == 1 && ch[i] == 0) {
					ch[i] = 1;
					q.push(i);
				}
			}
		}
	}

	int main() {
		cin >> n >> m >> start;

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			graph[a][b] = 1;
			graph[b][a] = 1;
		}

		// 1. dfs 시작
		dfs(start);

		// 2. ch 메모리 초기화
		memset(ch, 0, sizeof(ch));
		cout << "\n";
		// 3. bfs 시작
		bfs(start);

		return 0;
	}
}

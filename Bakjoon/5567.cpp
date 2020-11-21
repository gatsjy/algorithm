#include <bits/stdc++.h>

using namespace std;

namespace _5567 {
	vector<int> graph[501];
	int ch[501];

	int cnt = 0;
	int main() {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int start, end;
			cin >> start >> end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}

		// 첫번째 상근이의 친구들을 구한다.
		for (int i = 0; i < graph[1].size(); i++) {
			if (!ch[graph[1][i]]) ch[graph[1][i]] = 1;
			int next = graph[1][i];
			// 상근이의 친구들의 친구들까지 구해서 체크한다.
			for (int j = 0; j < graph[next].size(); j++) {
				if (!ch[graph[next][j]]) {
					ch[graph[next][j]] = 1;
				}
			}
		}

		// 상근이를 제외한 나머지 친구들의 수를 센다.
		for (int i = 2; i <= n; i++) {
			if (ch[i]) cnt++;
		}

		cout << cnt;

		return 0;
	}
}
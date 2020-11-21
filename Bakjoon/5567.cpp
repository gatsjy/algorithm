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

		// ù��° ������� ģ������ ���Ѵ�.
		for (int i = 0; i < graph[1].size(); i++) {
			if (!ch[graph[1][i]]) ch[graph[1][i]] = 1;
			int next = graph[1][i];
			// ������� ģ������ ģ������� ���ؼ� üũ�Ѵ�.
			for (int j = 0; j < graph[next].size(); j++) {
				if (!ch[graph[next][j]]) {
					ch[graph[next][j]] = 1;
				}
			}
		}

		// ����̸� ������ ������ ģ������ ���� ����.
		for (int i = 2; i <= n; i++) {
			if (ch[i]) cnt++;
		}

		cout << cnt;

		return 0;
	}
}
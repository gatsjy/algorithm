#include <bits/stdc++.h>

/*
2020-11-21, Gatsjy, 1707(백준)
*/

using namespace std;

namespace _1707 {

	int K, V, E;
	vector<int> graph[20001];
	int vColor[20001];

	void dfs(int v, int color) {
		vColor[v] = color;
		for (int i = 0; i < graph[v].size(); i++) {
			int next = graph[v][i];
			if (!vColor[next]) {
				dfs(next, 3 - color);
			}
		}
	}

	bool isBinary() {
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int next = graph[i][j];
				if (vColor[i] == vColor[next]) {
					return false;
				}
			}
		}
		return true;
	}

	int main() {

		cin >> K;
		while (K--) {
			cin >> V >> E;

			// 해당 정점 초기화
			for (int i = 0; i < 20001; i++) {
				graph[i].clear();
			}
			memset(vColor, 0, sizeof(vColor));

			for (int i = 0; i < E; i++) {
				int start, end;
				cin >> start >> end;
				graph[start].push_back(end);
				graph[end].push_back(start);
			}

			// 이분 그래프 만드는 작업
			for (int i = 1; i <= V; i++) {
				if (!vColor[i]) {
					dfs(i, 1);
				}
			}

			// 이분 그래프 인지 확인 하는 부분
			if (isBinary()) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
		return 0;
	}
}

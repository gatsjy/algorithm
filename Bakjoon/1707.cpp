#include <bits/stdc++.h>

using namespace std;

const int MAX = 20000 + 1;
int k, v, e;
vector<int> graph[MAX];
int nodeColor[MAX];

void dfs(int nodeNum, int color) {
	nodeColor[nodeNum] = color;

	for (int i = 0; i < graph[nodeNum].size(); i++) {
		int next = graph[nodeNum][i];
		if (!nodeColor[next]) {
			dfs(next, 3 - color);
		}
	}
}

// 서로 연결된 노드가 같은 색깔이면 이분 그래프가 아니다.
bool isBiGraph(void) {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (nodeColor[i] == nodeColor[next]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	cin >> k;
	while (k--) {
		// 초기화 해줍니다.
		for (int i = 0; i < MAX; i++) {
			graph[i].clear();
		}
		memset(nodeColor, 0, sizeof(nodeColor));

		cin >> v >> e;

		for (int i = 0; i < e; i++) {
			int start, end;
			cin >> start >> end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}

		for (int i = 1; i <= v; i++) {
			if (!nodeColor[i]) {
				dfs(i, 0);
			}
		}

		if (isBiGraph()) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}
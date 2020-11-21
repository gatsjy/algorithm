#include <bits/stdc++.h>

using namespace std;

namespace _9466 {
	int graph[100001];
	int ch[100001];
	bool cycle[100001];

	int T, N, E;
	int cnt = 0;
	void dfs(int v) {
		if (cycle[v] || ch[v] == -1) return;

		// 방문했음을 체크한다.
		if (ch[v] == 0) {
			ch[v] = 1;
		}
		// 방문을 했는데 다시 돌아옴 -> 즉 사이클이란 말
		// 사이클 여부를 체크한다.
		else if (ch[v] == 1) {
			cycle[v] = true;
			cnt++;
		}
		// 다음노드 방문
		dfs(graph[v]);
		// 노드의 방문이 끝나면 ch를 풀어준다.
		// 그대신 -1로 풀어 주어서 다시 방문할 필요가 없음을 인식시킴
		ch[v] = -1;
	}
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> T;
		while (T--) {
			int n;
			memset(ch, 0, sizeof(ch));
			memset(cycle, 0, sizeof(cycle));
			cin >> n;
			for (int i = 1; i <= n; i++) {
				cin >> graph[i];
			}
			cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (!ch[i]) {
					dfs(i);
				}
			}
			cout << n - cnt << "\n";
		}
		return 0;
	}
}

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

		// �湮������ üũ�Ѵ�.
		if (ch[v] == 0) {
			ch[v] = 1;
		}
		// �湮�� �ߴµ� �ٽ� ���ƿ� -> �� ����Ŭ�̶� ��
		// ����Ŭ ���θ� üũ�Ѵ�.
		else if (ch[v] == 1) {
			cycle[v] = true;
			cnt++;
		}
		// ������� �湮
		dfs(graph[v]);
		// ����� �湮�� ������ ch�� Ǯ���ش�.
		// �״�� -1�� Ǯ�� �־ �ٽ� �湮�� �ʿ䰡 ������ �νĽ�Ŵ
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

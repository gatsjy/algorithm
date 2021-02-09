#include <bits/stdc++.h>

// �ƹ��� ã�ƺ� �ڵ�� �� ������ © �� ������ ������ �ƴϴ�!
using namespace std;

#define MAX 1005

namespace _2310 {
	struct {
		char type;
		int cost;
	} room[MAX];

	vector<int> graph[MAX];
	int n, b, c;
	char a;
	bool res = false;
	int ch[MAX];

	void dfs(int v, int money) {
		if (room[v].type == 'L' && room[v].cost > money) {
			money = room[v].cost;
		}
		else if (room[v].type == 'T') {
			if (money < room[v].cost) {
				return;
			}
			else {
				money -= room[v].cost;
			}
		}
		// �ϴ� ���� ������ �������״ٸ�?
		ch[v] = 1; // üũó���ϰ�
		// ��� �� �Ǵ��Ѵ�.
		if (v == n) {
			res = true;
			return;
		}
		else {
			for (int i = 0; i < graph[v].size(); i++) {
				int next = graph[v][i];
				if (ch[next] == 0) {
					dfs(next, money);
				}
			}
		}
	}
	int main() {
		while (1) {
			cin >> n;
			if (n == 0) break;
			// ���� �� �ʱ�ȭ
			for (int i = 0; i < MAX; i++) {
				graph[i].clear();
			}
			res = false;
			memset(ch, 0, sizeof(ch));
			for (int i = 1; i <= n; i++) {
				cin >> a >> b >> c;
				room[i] = { a,b };
				while (c != 0) {
					graph[i].push_back(c);
					cin >> c;
				}
			}

			// ���۹��� 1, ���� ���� 0��
			dfs(1, 0);

			if (res) {
				cout << "Yes" << "\n";
			}
			else {
				cout << "No" << "\n";
			}
		}
		return 0;
	}

}

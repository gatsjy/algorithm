#include <bits/stdc++.h>

// 아무리 찾아본 코드라도 내 손으로 짤 수 없으면 내것이 아니다!
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
		// 일단 위의 조건을 충족시켰다면?
		ch[v] = 1; // 체크처리하고
		// 결과 값 판단한다.
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
			// 각종 값 초기화
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

			// 시작방은 1, 시작 돈은 0원
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

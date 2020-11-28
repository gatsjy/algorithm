#include <bits/stdc++.h>

using namespace std;

namespace _15686 {
	struct position {
		int y;
		int x;
		position(int a, int b) {
			y = a;
			x = b;
		}
	};

	vector<position> home;
	vector<position> chicken;
	int visited[15];
	int board[51][51];

	int N, M;
	int res = 2147000000;

	// �Ÿ� ����ϴ� ��
	int calDis(position a, position b) {
		return abs(a.y - b.y) + abs(a.x - b.x);
	}

	void dfs(int idx, int level) {
		if (level == M) {
			int citydis = 0;
			// ���⼭ ���� ġŲ���� ������ �Ÿ��� �ּҰ��� ���ϱ� �����Ѵ�.
			for (int i = 0; i < home.size(); i++) {
				int homedis = 2147000000;
				for (int j = 0; j < chicken.size(); j++) {
					if (visited[j]) {
						homedis = min(homedis, calDis(home[i], chicken[j]));
					}
				}
				citydis += homedis;
			}
			if (res > citydis) res = citydis;
			return;
		}

		// dfs�� ������ �κ�
		if (idx == chicken.size()) return;

		// ������ ġŲ���� ����
		visited[idx] = 1;
		dfs(idx + 1, level + 1);
		// ������ ġŲ���� ����x
		visited[idx] = 0;
		dfs(idx + 1, level);
	}


	int main() {
		cin >> N >> M;
		int input;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> input;
				if (input == 1) {
					home.push_back(position(i, j));
				}
				else if (input == 2)
				{
					chicken.push_back(position(i, j));
				}
			}
		}

		dfs(0, 0);

		cout << res;

		return 0;
	}
}

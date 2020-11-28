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

	// 거리 계산하는 식
	int calDis(position a, position b) {
		return abs(a.y - b.y) + abs(a.x - b.x);
	}

	void dfs(int idx, int level) {
		if (level == M) {
			int citydis = 0;
			// 여기서 부터 치킨집과 집과의 거리의 최소값을 구하기 시작한다.
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

		// dfs를 끝내는 부분
		if (idx == chicken.size()) return;

		// 다음의 치킨집을 선택
		visited[idx] = 1;
		dfs(idx + 1, level + 1);
		// 다음의 치킨집을 선택x
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

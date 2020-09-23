#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> ch;

namespace 네트워크 {
	int solution(int n, vector<vector<int>> computers) {
		int answer = 0;
		vector<vector<int>> map = vector<vector<int>>(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (computers[i][j] == 1) {
					map[i].push_back(j);
				}
			}
		}

		queue<int> q;
		ch = vector<bool>(n);
		for (int i = 0; i < n; i++) {
			if (!ch[i]) {
				q.push(i);
				ch[i] = true;
				answer++;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					for (int i = 0; i < map[cur].size(); i++) {
						int togo = map[cur][i];
						if (!ch[togo]) {
							q.push(togo);
							ch[togo] = true;
						}
					}
				}
			}
		}
		return answer;
	}

	int main() {
		int n = 3;
		//vector<vector<int>> v = { {1, 1, 0},{1, 1, 1},{0, 1, 1}};
		vector<vector<int>> v = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
		solution(n, v);

		return 0;
	}
}

#include <bits/stdc++.h>

using namespace std;

namespace _14502 {
	int dy[4] = { 0,1,0,-1 };
	int dx[4] = { 1,0,-1,0 };
	int n, m;
	int res = -1;

	// 오늘 배운점 vector에 넣을 때는 map[i][j]
	// queue같은 곳에 넣을땐 yy,xx로 넣는다. 그래야 꺼내와서 바로 map에 map[i][j] 로 넣을 수 있다.
	// 함수 x좌표 y좌표가 반대로 먹는다고 생각하면 빠를 듯..
	int calVirus(vector<vector<int>> map, pair<int, int> a, pair<int, int> b, pair<int, int> c) {
		// 일단 받아온 map에 벽을 설치한다.
		map[a.second][a.first] = 1;
		map[b.second][b.first] = 1;
		map[c.second][c.first] = 1;

		// 바이러스를 전파한다.
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 2) {
					q.push({ j, i });
					while (!q.empty()) {
						auto cur = q.front();
						q.pop();
						for (int k = 0; k < 4; k++) {
							int xx = cur.second + dx[k];
							int yy = cur.first + dy[k];
							if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
							if (map[xx][yy] == 1 || map[xx][yy] == 2) continue;
							map[xx][yy] = 2;
							q.push({ yy,xx });
						}
					}
				}
			}
		}

		int safe = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) safe++;
			}
		}

		return safe;
	}

	int main() {

		cin >> n >> m;
		vector<vector<int>> a = vector<vector<int>>(n, vector<int>(m, 0));

		// map을 만든다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		// 벽을 세울 수 있는 장소를 구한다.
		// pair<y,x>
		vector<pair<int, int>> wall;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					wall.push_back({ j,i });
				}
			}
		}

		for (int i = 0; i < wall.size(); i++) {
			for (int j = i + 1; j < wall.size(); j++) {
				for (int k = j + 1; k < wall.size(); k++) {
					int tmpCnt = calVirus(a, wall[i], wall[j], wall[k]);
					if (res < tmpCnt) res = tmpCnt;
				}
			}
		}

		cout << res;
		return 0;
	}
}
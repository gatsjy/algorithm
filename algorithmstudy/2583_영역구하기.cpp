#include<bits/stdc++.h>

using namespace std;

namespace 영역구하기_2583 {
	int dy[4] = { -1,0,1,0 };
	int dx[4] = { 0,1,0,-1 };
	int _map[104][104], m, n, k;
	int x11, x22, y11, y22;
	vector<int> res;
	int dfs(int y, int x) {
		_map[y][x] = 1;
		int res = 1;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n || _map[ny][nx] == 1)continue;
			res += dfs(ny, nx);
		}
		return res;
	}
	int main() {

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> m >> n >> k;

		// 값 매핑
		for (int i = 0; i < k; i++) {
			cin >> x11 >> y11 >> x22 >> y22;
			for (int x = x11; x < x22; x++) {
				for (int y = y11; y < y22; y++) {
					_map[y][x] = 1;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (_map[i][j] != 1) {
					res.push_back(dfs(i, j));
				}
			}
		}

		sort(res.begin(), res.end());
		cout << res.size() << "\n";
		for (int _res : res) cout << _res << " ";
		return 0;
	}
}

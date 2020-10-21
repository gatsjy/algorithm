#include <bits/stdc++.h>

using namespace std;

namespace _47{
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int main() {
		int n;
		cin >> n;
		vector<vector<int>> map = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
			}
		}

		int cnt = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i + dx[0]][j + dy[0]]
					&& map[i][j] > map[i + dx[1]][j + dy[1]]
					&& map[i][j] > map[i + dx[2]][j + dy[2]]
					&& map[i][j] > map[i + dx[3]][j + dy[3]]) {
					cnt++;
				}
			}
		}
		cout << cnt;
		return 0;
	}
}

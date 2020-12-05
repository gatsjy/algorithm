#include <bits/stdc++.h>

using namespace std;

namespace _5427 {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int c, w, h;

	string board[1002];
	int dist1[1002][1002];
	int dist2[1002][1002];

	int main() {
		//세로행, 가로열
		cin >> c;
		while (c--) {
			cin >> w >> h;
			// board 초기화
			for (int i = 0; i < h; i++) {
				board[i] = "";
			}
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					dist1[i][j] = -1;
					dist2[i][j] = -1;
				}
			}

			for (int i = 0; i < h; i++) {
				cin >> board[i];
			}
			queue<pair<int, int>> q1; // 불의 위치
			queue<pair<int, int>> q2; // 상근이 위치
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (board[i][j] == '*') { // 불의 위치
						q1.push({ i,j });
						dist1[i][j] = 0;
					}
					if (board[i][j] == '@') { // 상근이의 위치 체큰
						q2.push({ i,j });
						dist2[i][j] = 0;
					}
				}
			}

			// 불의 번짐 표현
			while (!q1.empty()) {
				auto cur = q1.front(); q1.pop();
				for (int i = 0; i < 4; i++) {
					int xx = cur.first + dx[i];
					int yy = cur.second + dy[i];
					if (xx < 0 || yy < 0 || xx >= h || yy >= w) continue;
					if (board[xx][yy] == '#' || dist1[xx][yy] >= 0) continue;
					dist1[xx][yy] = dist1[cur.first][cur.second] + 1;
					q1.push({ xx,yy });
				}
			}

			bool flag = false;
			// 상근이의 탈출 표현
			while (!q2.empty() && !flag) {
				auto cur = q2.front(); q2.pop();
				for (int i = 0; i < 4; i++) {
					int xx = cur.first + dx[i];
					int yy = cur.second + dy[i];
					if (xx < 0 || yy < 0 || xx >= h || yy >= w) {
						cout << dist2[cur.first][cur.second] + 1 << "\n";
						flag = true;
						break;
					};
					if (board[xx][yy] == '#' || dist2[xx][yy] >= 0) continue;
					if (dist1[xx][yy] != -1 && dist1[xx][yy] <= dist2[cur.first][cur.second] + 1) continue;
					dist2[xx][yy] = dist2[cur.first][cur.second] + 1;
					q2.push({ xx,yy });
				}
			}

			if (!flag) {
				cout << "IMPOSSIBLE" << "\n";
			}
		}
		return 0;
	}
}

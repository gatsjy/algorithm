#include <bits/stdc++.h>

using namespace std;

namespace _16948 {
	int dx[6] = { -2,-2,0,0,2,2 };
	int dy[6] = { -1,1,-2,2,-1,1 };
	int n;
	int board[202][202];
	queue<pair<int, int>> q;
	int a, b, targetx, targety;
	int main() {
		cin >> n;
		cin >> a >> b >> targetx >> targety;

		memset(board, -1, sizeof(board));
		board[a][b] = 0;
		q.push({ a,b });

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == targetx && y == targety) {
				break;
			}
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (board[nx][ny] == -1) {
					board[nx][ny] = board[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}

		cout << board[targetx][targety];
		return 0;
	}
}
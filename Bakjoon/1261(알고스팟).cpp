#include<bits/stdc++.h>

using namespace std;

namespace _1261 {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int board[101][101];
	int ch[101][101];

	int n, m;

	int main() {

		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int n;
				scanf_s("%1d", &n);
				board[i][j] = n;
				ch[i][j] = 2147000000;
			}
		}

		queue<pair<int, int>> q;
		ch[0][0] = 0;
		q.push({ 0, 0 });

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
				if (board[xx][yy] == 1) // 벽일때
				{
					if (ch[xx][yy] > ch[x][y] + 1) {
						ch[xx][yy] = ch[x][y] + 1;
						q.push({ xx,yy });
					}
				}
				else // 벽이 아닐때
				{
					if (ch[xx][yy] > ch[x][y]) {
						ch[xx][yy] = ch[x][y];
						q.push({ xx,yy });
					}
				}
			}
		}

		// printf를 사용하는 경우... sync_with_stdio를 쓰면 안된다..
		printf("%d", ch[m - 1][n - 1]);
		return 0;
	}
}
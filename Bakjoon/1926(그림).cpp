#include <bits/stdc++.h>

using namespace std;

namespace _1926 {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

#define X second
#define Y first

	int maxsize = 0;
	int paint = 0;
	int board[501][501];
	int ch[501][501];
	int N, M;

	void input() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[i][j];
			}
		}
	}

	void solve() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (ch[i][j] || board[i][j] == 0) continue;
				paint++;
				queue<pair<int, int>> q;
				q.push({ i,j });
				ch[i][j] = 1;
				int size = 0;
				while (!q.empty()) {
					size++;
					pair<int, int> cur = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						int yy = cur.Y + dy[i];
						int xx = cur.X + dx[i];
						if (yy < 0 || xx < 0 || yy >= N || xx >= M) continue;
						if (board[yy][xx] != 1 || ch[yy][xx]) continue;
						ch[yy][xx] = 1;
						q.push({ yy,xx });
					}
				}
				if (maxsize < size) maxsize = size;
			}
		}
	}

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> N >> M;
		input();
		solve();
		cout << paint << "\n";
		cout << maxsize;
		return 0;
	}
}
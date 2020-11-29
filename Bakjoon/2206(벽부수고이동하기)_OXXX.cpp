#include <bits/stdc++.h>

using namespace std;

namespace _2206 {
	struct pos {
		int y;
		int x;
		int cnt;
		pos(int a, int b, int c) {
			y = a;
			x = b;
			cnt = c;
		}
	};

	int board[1001][1001];
	int dis[1001][1001][2];
	int dy[4] = { 1,0,-1,0 };
	int dx[4] = { 0,1,0,-1 };
	int N, M;

	int bfs(int y, int x, int cnt) {
		queue<pos> q;
		q.push(pos(y, x, cnt));
		dis[y][x][cnt] = 1;

		while (!q.empty()) {
			int y = q.front().y;
			int x = q.front().x;
			int cnt = q.front().cnt;
			q.pop();

			// 다음 단계가 도착점이라면?
			if (y == N - 1 && x == M - 1) {
				return dis[y][x][cnt];
			}

			for (int i = 0; i < 4; i++) {
				int yy = y + dy[i];
				int xx = x + dx[i];
				if (yy < 0 || xx < 0 || yy >= N || xx >= M) continue;
				// 벽이 있고, 벽을 한번도 부순적이 없다면
				if (board[yy][xx] == 1 && cnt) {
					dis[yy][xx][cnt - 1] = dis[y][x][cnt] + 1;
					q.push(pos(yy, xx, cnt - 1));
				}
				else if (board[yy][xx] == 0 && dis[yy][xx][cnt] == 0) {
					dis[yy][xx][cnt] = dis[y][x][cnt] + 1;
					q.push(pos(yy, xx, cnt));
				}
			}
		}
		return -1;
	}

	int main() {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int input;
				scanf_s("%1d", &input);
				board[i][j] = input;
			}
		}

		cout << bfs(0, 0, 1);

		return 0;
	}
}
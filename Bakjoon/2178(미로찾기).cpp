#include <bits/stdc++.h>

using namespace std;

namespace _2178 {
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	string board[102];
	int dis[102][102];

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> board[i];
		}

		for (int i = 0; i < N; i++) {
			fill(dis[i], dis[i] + M, -1);
		}

		queue<pair<int, int>> q;
		q.push({ 0,0 });
		dis[0][0] = 0;
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int yy = cur.first + dy[i];
				int xx = cur.second + dx[i];
				if (yy < 0 || xx < 0 || yy >= N || yy >= M)continue;
				if (dis[yy][xx] >= 0 || board[yy][xx] != '1') continue;
				dis[yy][xx] = dis[cur.first][cur.second] + 1;
				q.push({ yy,xx });
			}
		}
		cout << dis[N - 1][M - 1] + 1;
	}
}
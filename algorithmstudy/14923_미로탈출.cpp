#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int visited[1001][1001], a[1001][1001], b[1001][1001], res = 2147000000, n,m, sy,sx,ey,ex,y,x;
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	cin >> sy >> sx;
	cin >> ey >> ex;
	sy = sy - 1; sx = sx - 1; ey = ey - 1; ex = ex - 1;

	// 처음부터 끝까지 전부해보기...
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) v.push_back({ i,j });
		}
	}

	// 1값이 들어있는 곳 부터 전부 돌려봅니다.
		// 배열 복사
		copy(&a[0][0], &a[0][0] + 1001 * 1001, &b[0][0]);
		fill(&visited[0][0], &visited[0][0] + 1001 * 1001, 0);
		b[v[i].first][v[i].second] = 0;

		// bfs 시작
		queue<pair<int, int>> q;
		visited[sy][sx] = 1;
		q.push({ sy,sx });

		while (q.size()) {
			tie(y, x) = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if (visited[ny][nx] || b[ny][nx] == 1)continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
		res = min(res, visited[ey][ex]);
	}
	
	if (res = 2147000000) {
		cout << -1;
	}
	else {
		cout << res-1;
	}
	return 0;
}
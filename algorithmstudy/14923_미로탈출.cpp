#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct c {
	int x;
	int y;
	int magic;
};
int visited[1001][1001][2], a[1001][1001], res = 2147000000, n,m, sy,sx,ey,ex,y,x;

int bfs(int y, int x) {
	queue<c> q;
	q.push({ y,x,0 });
	visited[y][x][0] = 1;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int magic = q.front().magic;
		if (y == ey && x == ex) {
			return visited[y][x][magic];
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (a[ny][nx] == 0 ) {
				if (visited[ny][nx][magic] == 0) {
					visited[ny][nx][magic] = visited[y][x][magic] + 1;
					q.push({ ny,nx,magic });
				}
			}
			if (a[ny][nx] == 1) {
				if (magic == 0)
				{
					visited[ny][nx][1] = visited[y][x][magic] + 1;
					q.push({ ny,nx,1 });
				}

			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	cin >> sx >> sy;
	cin >> ex >> ey;
	sy = sy - 1; sx = sx - 1; ey = ey - 1; ex = ex - 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int res = bfs(sy, sx);

	cout << res;
	return 0;
}
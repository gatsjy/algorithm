#include <bits/stdc++.h>

using namespace std;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
int n, m;
int board[1001][1001];

int cnt = 0;

// 1. bfs로 풀이
void bfs(int sx, int sy) {
	board[sx][sy] = 1;
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == 1) continue;
			q.push({ nx,ny });
			board[nx][ny] = 1;
		}
	}
}

bool dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) {
		return false;
	}
	if (board[x][y] == 0) {
		board[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			dfs(nx, ny);
		}
		return true;
	}
	return false;
}

// 2. dfs로 풀이
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
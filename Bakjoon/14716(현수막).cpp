#include <bits/stdc++.h>

using namespace std;

#define MAX 251

int n, m, cnt = 0;
int ch[MAX][MAX];
int board[MAX][MAX];

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
void dfs(int x, int y) {
	if (ch[x][y] == 1) {
		return;
	}
	ch[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (board[nx][ny] == 0 || ch[nx][ny] == 1) continue;
		dfs(nx, ny);
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// dfsΩ√¿€
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && ch[i][j] == 0) {
				cnt++;
				dfs(i, j);
			}
		}
	}

	cout << cnt;

	return 0;
}
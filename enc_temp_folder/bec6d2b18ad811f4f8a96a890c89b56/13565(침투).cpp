#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int n, m;
string s;
int ch[MAX][MAX];
int board[MAX][MAX];

void dfs(int x, int y) {
	ch[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (ch[nx][ny] || board[nx][ny]) continue;
		dfs(nx, ny);
	}
}
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '1') {
				board[i][j] = 1;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		if (board[0][j] == 0 && ch[0][j] == 0) {
			dfs(0, j);
		}
	}

	for (int i = 0; i < m; i++) {
		if (ch[n - 1][i]) {
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";
	return 0;
}
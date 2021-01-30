#include <bits/stdc++.h>

using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[501][501];
int dp[501][501];
int n;
int res = 1;

int dfs(int x, int y) {
	// ����� ��������
	if (dp[x][y] != 0) return dp[x][y];
	// �⺻���� 1 ä���ֱ� (�ֳ��ϸ� �ּҰ� 1���̱� ������)
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (board[x][y] < board[nx][ny]) {
			dp[x][y] = max(dp[x][y],dfs(nx, ny) + 1);
		}
	}
	return dp[x][y];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res = max(dfs(i, j), res);
		}
	}

	cout << res;
	return 0;
}
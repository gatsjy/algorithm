#include <bits/stdc++.h>

using namespace std;

// stack구조에 대해 돌아가는 방법을 조금은.. 알것 같다!!
#define MAX 21
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
char board[MAX][MAX];
int ch[MAX][MAX];
int dch[26];
int r, c;
string s;
int res = -1;
void dfs(char in, int level, int x, int y) {
	dch[in - 'A'] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (!dch[board[nx][ny]-'A']) {
			dfs(board[nx][ny], level + 1, nx, ny);
			dch[board[nx][ny]-'A'] = 0;
		}
		else {
			res = max(res, level);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			board[i][j] = s[j];
		}
	}
	dfs(board[0][0], 1, 0 , 0);
	cout << res;

	return 0;
}
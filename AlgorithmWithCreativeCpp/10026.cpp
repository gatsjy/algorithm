#include <bits/stdc++.h>

using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int N;

char board[101][101];
bool ch[101][101];
string s;

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	ch[y][x] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy < 0 || xx < 0 || yy >= N || xx >= N) continue;
			if (ch[yy][xx] == 1 || board[y][x] != board[yy][xx]) continue;
			ch[yy][xx] = 1;
			q.push({ yy,xx });
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!ch[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << " ";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'G') board[i][j] = 'R';
		}
	}

	memset(ch, 0, sizeof(ch));
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!ch[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}
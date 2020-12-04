#include <bits/stdc++.h>

using namespace std;

string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 전파 시간
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	// 세로(행), 가로(열)
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist1[i][j] = -1;
			dist2[i][j] = -1;
		}
	}
	queue<pair<int, int>> q1; // 불의 이동을 담을 큐
	queue<pair<int, int>> q2; // 지훈이의 이동을 담을 큐
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				dist1[i][j] = 0;
				q1.push({ i,j });
			}
			if (board[i][j] == 'J') {
				dist2[i][j] = 0;
				q2.push({ i,j });
			}
		}
	}

	// 불의 이동을 계산한다.
	while (!q1.empty()) {
		auto cur = q1.front(); q1.pop();
		for (int i = 0; i < 4; i++) {
			int xx = cur.first + dx[i];
			int yy = cur.second + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (board[xx][yy] == '#' || dist1[xx][yy] >= 0) continue;
			dist1[xx][yy] = dist1[cur.first][cur.second] + 1;
			q1.push({ xx,yy });
		}
	}

	// 지훈이의 탈출을 계산한다.
	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int i = 0; i < 4; i++) {
			int xx = cur.first + dx[i];
			int yy = cur.second + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
				cout << dist2[cur.first][cur.second] + 1;
				return 0;
			}
			if (dist2[xx][yy] >= 0) continue;
			if (board[xx][yy] == '#') continue;
			// 가려는 곳이 불이 번져 있으면 가지 못한다. (번져있다는 뜻은 내가 가기 이전 시간부터 불이 있다.)
			// 내가 가려고 하는 곳의 초가 현재보다 크면 이미 그곳은 불이 지나간 자리라는 뜻
			// 즉 내 초가 더 많아야 한다. -> 더 빨리 도달했다는 뜻
			if (dist1[xx][yy] != -1 && dist1[xx][yy] <= dist2[cur.first][cur.second] + 1) continue;
			q2.push({ xx,yy });
			dist2[xx][yy] = dist2[cur.first][cur.second] + 1;
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}
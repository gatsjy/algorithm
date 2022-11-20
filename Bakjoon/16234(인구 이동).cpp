#include <bits/stdc++.h>

using namespace std;

// 가중치가 같을 경우.. bfs
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0 ,1 , 0 -1 };
int n, m,l;
char a[54][54];
int visited[54][54];

bool isContinue(int y, int x) {
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;
	queue<pair<int, int>> nq;
	nq.push({ y,x });
	while (nq.size()) {
		tie(y, x) = nq.front(); nq.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (abs(a[y][x]-a[ny][nx]) >= )
		}
	}
}

void bfs(int y, int x) {
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if(a[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}

	}
}

int main() {
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	// 어떻게 bfs를 진행시키지? -> bfs를 두개 돌려야 한다.
	
}
#include <bits/stdc++.h>

using namespace std;
int board[51][51];
int n, m, a, b, dir;
int cnt = 0;

void takeclean(pair<int,int> cur) {
	if (board[cur.first][cur.second] == 0) {
		board[cur.first][cur.second] = 2; 
		cnt++;
	}
}
int nextDir(int dir) {
	if (dir == 0) {
		return 3;
	}
	else if (dir == 1) {
		return 0;
	}
	else if (dir == 2) {
		return 1;
	}
	else if (dir == 3) {
		return 2;
	}
}

// 바라보는 곳에 청소할 곳이 있는지 없는지 파악하는 메서드
bool calCleanArea(int dir, pair<int,int> cur) {
	int x = cur.first;
	int y = cur.second;
	int cnt = 0;
	// 0 : 북
	if (dir == 0) {
		if (x - 1 < 0) return false;
		for (int i = x-1; i >= 0; i--) {
			if (board[i][y] == 0) {
				cnt++;
			}
			else if (board[i][y] == 1) {
				break;
			}
		}
	}
	// 1 : 동
	else if (dir == 1) {
		if (y + 1 >= m) return false;
		for (int i = y + 1; i < m; i++) {
			if (board[x][i] == 0) {
				cnt++;
			}
			else if (board[x][i] == 1) {
				break;
			}
		}
	}
	// 2 : 남
	else if (dir == 2) {
		if (x + 1 >= n) return false;
		for (int i = x + 1; i < n; i++) {
			if (board[i][y] == 0) {
				cnt++;
			}
			else if (board[i][y] == 1) {
				break;
			}
		}
	}
	// 3 : 서
	else if (dir == 3) {
		if (y - 1 < 0) return false;
		for (int i = y - 1; i >= 0; i--) {
			if (board[x][i] == 0) {
				cnt++;
			}
			else if(board[x][i]==1){
				break;
			}
		}
	}
	if (cnt > 0) {
		return true;
	}
	return false;
}

void moveForward(pair<int, int>& cur, int dir) {
	int x = cur.first;
	int y = cur.second;
	if (dir == 0) {
		x++;
	}
	else if (dir == 1) {
		y++;
	}
	else if (dir == 2) {
		x--;
	}
	else if (dir == 3) {
		y--;
	}
	cur = { x,y };
}

void moveBack(pair<int, int>& cur, int dir) {
	int x = cur.first;
	int y = cur.second;
	if (dir == 0) { // 북쪽을 바라보고 빽은 남쪽
		x--;
	}
	else if (dir == 1) { // 동쪽을 바라보고 빽은 서쪽
		y--;
	}
	else if (dir == 2) { // 
		x++;
	}
	else if (dir == 3) {
		y++;
	}
	cur = { x,y };
}

bool isBackOk(pair<int, int> cur, int dir) {
	int x = cur.first;
	int y = cur.second;
	if (dir == 0) {
		x--;
	}
	else if (dir == 1) {
		y--;
	}
	else if (dir == 2) { 
		x++;
	}
	else if (dir == 3) {
		y++;
	}
	if (x < 0 || y < 0 || (x >= n) || (y >= m)) return false;
	if (board[x][y] == 1) return false;
	return true;
}

int main() {
	cin >> n >> m >> a >> b >> dir;
	// 0 == 북 / 1 == 동 / 2 == 남 / 3 == 서
	pair<int, int> cur = { a, b};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}


	bool flag = true;
	while (flag) {
		// 1. 현재 위치를 청소한다.
		takeclean(cur);
		// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
		for (int i = 0; i < 4; i++) {
			// 다음 방향
			int ndir = nextDir(dir);
			// 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
			if (calCleanArea(ndir, cur)) {
				// 회전한다.
				dir = ndir;
				// 한칸 전진한다.
				moveForward(cur, dir);
				// 다시 처음부터 진행한다
				break;
			}
			else {
				continue;
			}
			if (i == 3) {
				if (isBackOk(cur, dir)) {
					moveBack(cur, dir);
				}
				else {
					flag = false;
					break;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}
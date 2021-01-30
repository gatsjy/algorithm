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

// �ٶ󺸴� ���� û���� ���� �ִ��� ������ �ľ��ϴ� �޼���
bool calCleanArea(int dir, pair<int,int> cur) {
	int x = cur.first;
	int y = cur.second;
	int cnt = 0;
	// 0 : ��
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
	// 1 : ��
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
	// 2 : ��
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
	// 3 : ��
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
	if (dir == 0) { // ������ �ٶ󺸰� ���� ����
		x--;
	}
	else if (dir == 1) { // ������ �ٶ󺸰� ���� ����
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
	// 0 == �� / 1 == �� / 2 == �� / 3 == ��
	pair<int, int> cur = { a, b};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}


	bool flag = true;
	while (flag) {
		// 1. ���� ��ġ�� û���Ѵ�.
		takeclean(cur);
		// 2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
		for (int i = 0; i < 4; i++) {
			// ���� ����
			int ndir = nextDir(dir);
			// ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
			if (calCleanArea(ndir, cur)) {
				// ȸ���Ѵ�.
				dir = ndir;
				// ��ĭ �����Ѵ�.
				moveForward(cur, dir);
				// �ٽ� ó������ �����Ѵ�
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
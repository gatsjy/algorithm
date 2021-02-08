#include <bits/stdc++.h>

using namespace std;

const int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
const int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int ch[6][6];
char x, y;
char nextx, nexty;
bool isValid() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (ch[i][j] == 0) return false;
		}
	}
	return true;
}

bool isNextOk(int prevx, int prevy, int x, int y, int gubun) {
	for (int dir = 0; dir < 8; dir++) {
		int nx = prevx + dx[dir];
		int ny = prevy + dy[dir];
		if (nx < 0 || ny < 0 || nx >= 6 || ny >= 6) continue;
		if (nx == x && ny == y) {
			if (ch[nx][ny] == 1&& gubun == 0) return false;
			if (nx == 0 && ny == 0 && gubun == 0) return false;
			return true;
		}
	}
	return false;
}

int main() {
	// 1. 처음 위치 
	cin >> x >> y;
	ch[y - '1'][x - 'A'] = 1;

	// 2. 두번째 부터 위치정보를 받는다.
	for (int i = 1; i < 36; i++) {
		if (i != 1) {
			x = nextx;
			y = nexty;
		}
		cin >> nextx >> nexty; 
		if (isNextOk(y - '1', x - 'A', nexty - '1', nextx - 'A', 0)) {
			ch[nexty - '1'][nextx - 'A'] = 1;
		}
		else {
			cout << "InValid";
			return 0;
		}
	}

	if (isValid()) {
		cout << "Valid";
	}
	else {
		cout << "InValid";
	}
	return 0;
}
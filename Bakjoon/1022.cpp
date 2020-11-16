#include <bits/stdc++.h>

using namespace std;
// го,©Л,╩С,аб
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m[5001][5001];
int r1, c1, r2, c2;
int main() {
	cin >> r1 >> c1 >> r2 >> c2;
	int rr = max(abs(r1), abs(r2));
	int rc = max(abs(c1), abs(c2));
	int size = max(rr, rc);

	int startx = size;
	int starty = size;
	m[startx][starty] = 1;
	int cnt = 2;
	int rotation = 1;
	for (int i = 1; i < 2 * size + 1; i++) {
		for (int j = 0; j < i; j++) {
			startx += dx[rotation % 4];
			starty += dy[rotation % 4];
			m[startx][starty] = cnt++;
		}
		rotation++;
		for (int j = 0; j < i; j++) {
			startx += dx[rotation % 4];
			starty += dy[rotation % 4];
			m[startx][starty] = cnt++;
		}
		rotation++;
	}
	for (int j = 0; j < 2*size; j++) {
		startx += dx[rotation % 4];
		starty += dy[rotation % 4];
		m[startx][starty] = cnt++;
	}

	for (int i = r1 + size; i <= r2 + size; i++) {
		for (int j = c1 + size; j <= c2 + size; j++) {
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
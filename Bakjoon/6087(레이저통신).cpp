//#include <bits/stdc++.h>
//
//using namespace std;
//
////https://bingorithm.tistory.com/2 ¹Ý·Ê¸ðÀ½
//int w, h;
//string s;
//int dy[4] = { 1,0,-1,0 };
//int dx[4] = { 0,1,0,-1 };
//char board[101][101];
//int ch[101][101];
//bool flag = true;
//int sx, sy, fx, fy;
//int main() {
//	cin >> w >> h;
//	for (int i = 0; i < h; i++) {
//		cin >> s;
//		for (int j = 0; j < w; j++) {
//			board[i][j] = s[j];
//			if (board[i][j] == 'C' && flag) {
//				sx = i; sy = j; flag = false;
//			}
//			else if(board[i][j]=='C'&&!flag) {
//				fx = i; fy = j;
//			}
//			ch[i][j] = 2147000000;
//		}
//	}
//	queue<pair<pair<int, int>,int>> q;
//	q.push({ { sx,sy },-1 });
//	ch[sx][sy] = 1;
//	while (!q.empty()) {
//		int x = q.front().first.first;
//		int y = q.front().first.second;
//		int dir = q.front().second;
//		q.pop();
//		if (x == fx && y == fy) {
//			return 0;
//		}
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
//			if (ch[nx][ny] > 0) continue;
//			if (board[nx][ny] == '*') continue;
//			q.push({ {nx,ny},i });
//			ch[nx][ny] = ch[x][y] + 1;
//			if (dir != i) {
//				cnt[nx][ny] = cnt[x][y] + 1;
//			}
//			else {
//				cnt[nx][ny] = cnt[x][y];
//			}
//		}
//	}
//
//	return 0;
//
//}
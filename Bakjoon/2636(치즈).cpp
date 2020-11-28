//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N, M;
//
//int dy[4] = { 1,0,-1,0 };
//int dx[4] = { 0,1,0,-1 };
//
//int board[101][101];
//int innerboard[101][101];
//bool ch[101][101];
//
//bool isMelt(int y, int x) {
//	for (int i = 0; i < 4; i++) {
//		int yy = y + dy[i];
//		int xx = x + dx[i];
//		if (board[yy][xx] == 0) {
//			return false;
//		}
//	}
//}
//
//void bfs(int y, int x) {
//	queue<pair<int, int>> q;
//	q.push({ y,x });
//	ch[y][x] = 1;
//
//	memset(innerboard, 0, sizeof(innerboard));
//	while (!q.empty()) {
//		int y = q.front().first;
//		int x = q.front().second;
//
//		if (innerboard[y][x] == 1) {
//			innerboard[y][x] = -1;
//		}
//
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int yy = y + dy[i];
//			int xx = x + dx[i];
//			if (yy < 1 || xx < 1 || yy > N + 1 || xx > M + 1) continue;
//			if (board[yy][xx] == 0)continue;
//			if (ch[yy][xx]) continue;
//			ch[yy][xx] = 1;
//			q.push({ yy,xx });
//		}
//	}
//
//}
//
//int main() {
//	cin >> N >> M;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> board[i][j];
//		}
//	}
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			if (board[i][j] == 1) {
//				memset(ch, 0, sizeof(ch));
//				bfs(i, j);
//				cout << i;
//			}
//		}
//	}
//}
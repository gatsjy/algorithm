#include <bits/stdc++.h>

using namespace std;
namespace _6087 {
	//https://bingorithm.tistory.com/2 반례모음

#define INF 2147000000

	int w, h;
	string s;
	int dy[4] = { 1,0,-1,0 };
	int dx[4] = { 0,1,0,-1 };
	char board[101][101];
	int ch[101][101];
	bool flag = true;
	int sx, sy, fx, fy;
	int main() {
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> s;
			for (int j = 0; j < w; j++) {
				board[i][j] = s[j];
				if (board[i][j] == 'C' && flag) {
					sx = i; sy = j; flag = false;
				}
				else if (board[i][j] == 'C' && !flag) {
					fx = i; fy = j;
				}
				ch[i][j] = INF;
			}
		}
		queue<pair<pair<int, int>, pair<int, int>>> q;

		// 한번에 네갈래로 모두 보내는 방법 (토마토에서 배웠음)
		for (int i = 0; i < 4; i++) {
			q.push({ { sx,sy }, { i,0 } });
		}
		ch[sx][sy] = 0;
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int dir = q.front().second.first;
			int mirror = q.front().second.second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nmirror = mirror;
				if (i != dir) {
					nmirror++;
				}
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (board[nx][ny] == '*') continue;
				// 만약 가려는 곳의 거울의 수가 더 적은걸로 업데이트한다.
				// 만약 이전의 ch의 mirrir수와 새로운 nmirror수가 같더라도 다시 bfs를 돌려야 한다. -> 이점 명시하기!!
				// 하지만 정확한 증거를 도출해내지 못함..
				if (ch[nx][ny] >= nmirror) {
					q.push({ {nx,ny},{i,nmirror} });
					ch[nx][ny] = nmirror;
				}
			}
		}
		if (ch[fx][fy] == INF) {
			cout << -1;
		}
		else {
			cout << ch[fx][fy];
		}
		return 0;
	}
}
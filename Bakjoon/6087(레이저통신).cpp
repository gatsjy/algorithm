#include <bits/stdc++.h>

using namespace std;
namespace _6087 {
	//https://bingorithm.tistory.com/2 �ݷʸ���

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

		// �ѹ��� �װ����� ��� ������ ��� (�丶�信�� �����)
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
				// ���� ������ ���� �ſ��� ���� �� �����ɷ� ������Ʈ�Ѵ�.
				// ���� ������ ch�� mirrir���� ���ο� nmirror���� ������ �ٽ� bfs�� ������ �Ѵ�. -> ���� ����ϱ�!!
				// ������ ��Ȯ�� ���Ÿ� �����س��� ����..
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
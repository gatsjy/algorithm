#include <bits/stdc++.h>

using namespace std;

namespace _16234 {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int n, l, r;
	int board[52][52];
	int ch[52][52];

	queue<pair<int, int>> q;
	queue<pair<int, int>> nq;
	int day = 0;
	// 연합을 해제하고 모든 국경을 닫는다 -> 이 뜻이 곧 하루에 한번만 인구이동을 시킨다는 뜻
	// 처음에 문제를 잘못해석해서 계속해서 똑같은 도시를 초기화함.. 그 결과 두시간 넘게 시간을 잡아먹음
	// 즉 문제를 잘 읽어야 한다는 뜻..

	// 1. 인구 병합하는 함수
	void bfs(int x, int y) {
		ch[x][y] = 1;
		while (!q.empty()) q.pop();
		q.push({ x,y });
		int cnt = 1;
		int sum = board[x][y];
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = cur.first + dx[i];
				int yy = cur.second + dy[i];
				if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
				if (ch[xx][yy]) continue;
				if (abs(board[cur.first][cur.second] - board[xx][yy]) >= l && abs(board[cur.first][cur.second] - board[xx][yy]) <= r) {
					q.push({ xx,yy });
					ch[xx][yy] = 1;
					cnt++;
					sum += board[xx][yy];
				}
			}
		}
	}

	// 2. 계속 이어나갈지 말지를 결정하는 함수
	bool isContinue() {
		// 사용 변수 초기화시키기..
		memset(ch, 0, sizeof(ch));
		while (!q.empty()) q.pop();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ch[i][j] == 0) {
					q.push({ i,j });
					while (!q.empty()) {
						pair<int, int> cur = q.front(); q.pop();
						for (int i = 0; i < 4; i++) {
							int xx = cur.first + dx[i];
							int yy = cur.second + dy[i];
							if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
							if (ch[xx][yy]) continue;
							if (abs(board[cur.first][cur.second] - board[xx][yy]) >= l && abs(board[cur.first][cur.second] - board[xx][yy]) <= r) {
								// 중복으로 nq에 저장되는 것을 막기위한 변수
								if (ch[cur.first][cur.second] == 0) {
									nq.push({ cur.first,cur.second });
								}
								bfs(cur.first, cur.second);
							}
						}
					}
				}
			}
		}
		// 만약 진행되어야할 nq가 비어있으면 다음은 없다
		// 진행되어야할 nq가 비어있지 않으면 다음 인구이동을 진행한다.
		if (nq.empty()) {
			return false;
		}
		else {
			return true;
		}
	}

	int main() {
		cin >> n >> l >> r;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		while (1) {
			if (!isContinue()) {
				break;
			}
			memset(ch, 0, sizeof(ch));
			day++;
			while (!q.empty()) q.pop();
			// 합병 작업
			while (!nq.empty()) {
				pair<int, int> cur = nq.front(); nq.pop();
				q.push({ cur.first, cur.second });
				ch[cur.first][cur.second] = 1;
				int cnt = 1;
				int sum = board[cur.first][cur.second];
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						int xx = cur.first + dx[i];
						int yy = cur.second + dy[i];
						if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
						if (ch[xx][yy]) continue;
						if (abs(board[cur.first][cur.second] - board[xx][yy]) >= l && abs(board[cur.first][cur.second] - board[xx][yy]) <= r) {
							q.push({ xx,yy });
							ch[xx][yy] = 1;
							cnt++;
							sum += board[xx][yy];
						}
					}
				}
				// 병합작업
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (ch[i][j] == 1) {
							board[i][j] = sum / cnt;
							ch[i][j] = 2;
						}
					}
				}
			}
		}

		cout << day;
		return 0;
	}
}

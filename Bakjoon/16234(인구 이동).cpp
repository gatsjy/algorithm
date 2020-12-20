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
	// ������ �����ϰ� ��� ������ �ݴ´� -> �� ���� �� �Ϸ翡 �ѹ��� �α��̵��� ��Ų�ٴ� ��
	// ó���� ������ �߸��ؼ��ؼ� ����ؼ� �Ȱ��� ���ø� �ʱ�ȭ��.. �� ��� �νð� �Ѱ� �ð��� ��Ƹ���
	// �� ������ �� �о�� �Ѵٴ� ��..

	// 1. �α� �����ϴ� �Լ�
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

	// 2. ��� �̾���� ������ �����ϴ� �Լ�
	bool isContinue() {
		// ��� ���� �ʱ�ȭ��Ű��..
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
								// �ߺ����� nq�� ����Ǵ� ���� �������� ����
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
		// ���� ����Ǿ���� nq�� ��������� ������ ����
		// ����Ǿ���� nq�� ������� ������ ���� �α��̵��� �����Ѵ�.
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
			// �պ� �۾�
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
				// �����۾�
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

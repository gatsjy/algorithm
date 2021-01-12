#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

namespace _16236 {
	struct shark {
		int size;
		int eat;
		int dist;
		int x;
		int y;

		shark() {}

		shark(int a, int b, int c, int d, int e) {
			size = a;
			eat = b;
			dist = c;
			x = d;
			y = e;
		}
	};

	struct feed {
		int x;
		int y;
		int dist;

		feed(int a, int b, int c) {
			x = a;
			y = b;
			dist = c;
		}

		// ���⿡ ���� �Ϻ��� ���ذ� �ʿ��ϴ�.
		// �Ÿ��� ���ٸ� �Ÿ��� ���� ���� ����
		bool operator<(const feed& b) const {
			if (dist == b.dist) {
				// x��ǥ�� ���ٸ� y��ǥ�� �������� �켱���� ����
				if (x == b.x) {
					return y > b.y;
				}
				else {
					// �Ÿ��� ���ٸ� x��ǥ�� �������� �켱���� ����
					return x > b.x;
				}
			}
			else {
				return dist > b.dist;
			}

		}
	};

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int n;
	int board[21][21];
	int ch[21][21];
	priority_queue<feed> pq;
	shark sk;

	// ����� ���̱��� �Ÿ��� Ž���Ѵ�.
	int calDist(int targetx, int targety) {
		queue<pair<int, int>> q;
		memset(ch, 0, sizeof(ch));
		ch[sk.x][sk.y] = 1;
		q.push({ sk.x, sk.y });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			// while�� �ȿ��� ����������
			if (targetx == x && targety == y) {
				return ch[targetx][targety];
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (board[nx][ny] > sk.size || ch[nx][ny] > 0) continue;
				ch[nx][ny] = ch[x][y] + 1;
				q.push({ nx,ny });
			}
		}
		return 0;
	}

	void searchfeed() {
		// �ϴ� pq�� ����ش�.
		while (!pq.empty()) pq.pop();
		// ���� ���̸� Ž��
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > 0 && board[i][j] < sk.size) {
					// ���̸� �߰������� ���̱��� �Ÿ��� Ž��
					int dist = calDist(i, j);
					if (dist > 0) {
						pq.push(feed(i, j, dist - 1));
					}
				}
			}
		}
	}

	// ��� ������� �Լ�
	void sizeup() {
		if (sk.eat == sk.size) {
			sk.size++;
			sk.eat = 0;
		}
	}

	int main() {
		cin >> n;


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				if (board[i][j] == 9) {
					sk = shark(2, 0, 0, i, j);
					board[i][j] = 0;
				}
			}
		}

		while (1) {
			sizeup();
			searchfeed();

			if (pq.empty()) {
				break; // �� �̻� ���̰Ÿ��� ������ ��!
			}
			else {
				auto cur = pq.top();
				sk.x = cur.x;
				sk.y = cur.y;
				sk.eat++;
				board[sk.x][sk.y] = 0;
				sk.dist += cur.dist;
			}
		}

		cout << sk.dist;

		return 0;
	}
}
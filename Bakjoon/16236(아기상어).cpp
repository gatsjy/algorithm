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

		// 여기에 대한 완벽한 이해가 필요하다.
		// 거리가 같다면 거리가 작은 것이 위로
		bool operator<(const feed& b) const {
			if (dist == b.dist) {
				// x좌표가 같다면 y좌표가 작을수록 우선순위 높다
				if (x == b.x) {
					return y > b.y;
				}
				else {
					// 거리가 같다면 x좌표가 작을수록 우선순위 높다
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

	// 상어의 먹이까지 거리를 탐색한다.
	int calDist(int targetx, int targety) {
		queue<pair<int, int>> q;
		memset(ch, 0, sizeof(ch));
		ch[sk.x][sk.y] = 1;
		q.push({ sk.x, sk.y });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			// while문 안에서 잡아줘야했음
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
		// 일단 pq를 비워준다.
		while (!pq.empty()) pq.pop();
		// 다음 먹이를 탐색
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > 0 && board[i][j] < sk.size) {
					// 먹이를 발견했으면 먹이까지 거리를 탐색
					int dist = calDist(i, j);
					if (dist > 0) {
						pq.push(feed(i, j, dist - 1));
					}
				}
			}
		}
	}

	// 상어 사이즈업 함수
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
				break; // 더 이상 먹이거리가 없으면 끝!
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
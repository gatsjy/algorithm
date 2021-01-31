#include <bits/stdc++.h>

using namespace std;

namespace _14503 {
	struct ROBOT {
		int x;
		int y;
		int dir;
	};

	// 나의 풀이와 엄청난 차이가 있다.. 어디서 이런 차이점이 나오는 걸까?? ㅠㅠ
	// 북, 동, 남, 서
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	ROBOT robot;
	int board[51][51];
	int n, m, a, b, dir;
	int cnt = 0;

	int main() {
		cin >> n >> m >> robot.x >> robot.y >> robot.dir;
		// 0 == 북 / 1 == 동 / 2 == 남 / 3 == 서
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
			}
		}

		queue<ROBOT> q;
		q.push(robot);

		while (!q.empty()) {
			ROBOT cur = q.front(); q.pop();
			if (board[cur.x][cur.y] == 0) {
				board[cur.x][cur.y] = 2;
				cnt++;
			}

			for (int dir = 0; dir < 4; ++dir) {
				ROBOT next;
				next.dir = (cur.dir + 3 - dir) % 4; //
				next.x = cur.x + dx[next.dir];
				next.y = cur.y + dy[next.dir];

				if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;
				if (board[next.x][next.y] != 0) continue;

				q.push(next);
				break; // queue에는 로봇 하나만 들어있어야 한다.
			}

			if (q.empty()) {
				ROBOT next;
				next.dir = cur.dir;
				next.x = cur.x + dx[(next.dir + 2) % 4]; // dir의 180도 회전 -> 후방을 봐야하기 때문에 (이 기법 기억하기)
				next.y = cur.y + dy[(next.dir + 2) % 4]; // dir의 180도 회전
				if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) break;
				if (board[next.x][next.y] == 1) break; // 벽이면 마친다.
				q.push(next);
			}
		}

		cout << cnt;

		return 0;
	}
}
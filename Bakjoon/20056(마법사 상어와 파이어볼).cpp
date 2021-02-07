#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

namespace _20056 {
	struct FIREBALL {
		int x, y;
		int m, s, d;
	};

	const int dx[8] = { -1,-1,0,1,1,1,0,-1 };
	const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

	int N, M, K;
	vector<FIREBALL> ball; // 파이어볼의 위치
	vector<int> map[50][50];

	void move() {
		vector<int> new_map[50][50];
		for (int i = 0; i < ball.size(); i++) {
			int dir = ball[i].d;
			int speed = (ball[i].s % N); // 최대 길이가 N이니까 N만큼 
			int nx = (ball[i].x + (dx[dir] * speed) + N) % N;
			int ny = (ball[i].y + (dy[dir] * speed) + N) % N;
			new_map[nx][ny].push_back(i);
			ball[i].x = nx;
			ball[i].y = ny;
		}

		// new맵 원본에 복사
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = new_map[i][j];
			}
		}
	}

	void sum() {
		vector<FIREBALL> new_ball;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (map[x][y].size() == 0) {
					continue;
				}
				if (map[x][y].size() == 1) {
					int idx = map[x][y][0];
					new_ball.push_back(ball[idx]);
					continue;
				}
				int sum_m = 0, sum_s = 0;
				bool odd = true, even = true;
				for (int k = 0; k < map[x][y].size(); k++) {
					int idx = map[x][y][k];
					sum_m += ball[idx].m;
					sum_s += ball[idx].s;
					if (ball[idx].d % 2 == 0) {
						odd = false;
					}
					else {
						even = false;
					}
				}
				if (sum_m / 5 == 0) {
					continue;
				}
				int cur_m = sum_m / 5;
				int cur_s = sum_s / map[x][y].size();
				for (int i = 0; i < 4; i++) {
					if (odd || even) {
						new_ball.push_back({ x,y,cur_m, cur_s, i * 2 });
					}
					else {
						new_ball.push_back({ x,y,cur_m, cur_s, i * 2 + 1 });
					}
				}
			}
		}

		ball = new_ball;
	}

	int solve() {
		while (K--) {
			move();
			sum();
		}
		int ret = 0;
		for (int i = 0; i < ball.size(); i++) {
			ret += ball[i].m;
		}
		return ret;
	}

	int main() {

		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> N >> M >> K;
		for (int i = 0; i < M; i++) {
			int x, y, m, s, d;
			cin >> x >> y >> m >> s >> d;
			x--, y--;
			ball.push_back({ x,y,m,s,d });
			map[x][y].push_back(i); // ball에 있는 인덱스를 넣는다.
		}

		int ret = solve();
		cout << ret;
		return 0;
	}
}
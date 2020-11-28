#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

namespace _2573 {
	int dy[4] = { 1,0,-1,0 };
	int dx[4] = { 0,1,0,-1 };

	int map[301][301];
	int tmap[301][301];
	bool ch[301][301];
	int N, M;
	int res = 0;

	// 이전 지도를 저장하는 부분
	void makeTmap() {
		memset(tmap, 0, sizeof(tmap));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				tmap[i][j] = map[i][j];
			}
		}
	}

	// 섬이 분리되었는지 알아내는 부분
	bool isSeparate() {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] > 0 && !ch[i][j]) {
					cnt++;
					queue<pair<int, int>> q;
					q.push({ i,j });
					if (cnt > 1) return true;
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++) {
							int yy = y + dy[i];
							int xx = x + dx[i];
							if (yy < 1 || xx < 1 || yy >= N + 1 || xx >= M + 1) continue;
							if (map[yy][xx] == 0 || ch[yy][xx]) continue;
							q.push({ yy,xx });
							ch[yy][xx] = 1;
						}
					}
				}
			}
		}
		return false;
	}

	void bfs(int y, int x) {

		queue<pair<int, int>> q;
		q.push({ y,x });
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int yy = y + dy[i];
				int xx = x + dx[i];
				// 한칸씩 넓혀줬으니까 +1을 더해서 조건문을 추가한다
				if (yy < 1 || xx < 1 || yy >= N + 1 || xx >= M + 1) continue;
				if (map[yy][xx] == 0 || ch[yy][xx]) continue;

				// 동서남북 얼음 == 0 계산
				// 계산할때는 녹기전 이전의 그림에서 수정해야 한다.
				int ice = 0;
				for (int j = 0; j < 4; j++) {
					if (tmap[yy + dy[j]][xx + dx[j]] == 0) ice++;
				}
				if (map[yy][xx] > ice) {
					map[yy][xx] -= ice;
				}
				else {
					map[yy][xx] = 0;
				}
				q.push({ yy,xx });
				ch[yy][xx] = 1;
			}
		}
	}


	int main() {

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				// 매 시점마다 초기화를 해줘야지 계속해서 bfs를 돌 수 있다.
				memset(ch, 0, sizeof(ch));
				if (map[i][j] > 0 && !ch[i][j]) {
					if (isSeparate()) {
						cout << res << endl;
						return 0;
					}
					memset(ch, 0, sizeof(ch));
					makeTmap();
					bfs(i, j);
					res++;
				}
			}
		}
		cout << 0 << endl;
		return 0;
	}
}
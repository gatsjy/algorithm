#include <iostream>
#include <vector>

using namespace std;

namespace BOJ_1913 {
	int map[1000][1000] = { 0, };

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n;
		int k;

		cin >> n >> k;
		// 1. 처음위치 설정
		int x = n / 2;
		int y = n / 2;
		int cnt = 1;
		map[x][y] = cnt++;

		int resx = 0;
		int resy = 0;
		// 2. 달팽이로 돌리기
		int stage = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				x = x + dx[stage % 4];
				y = y + dy[stage % 4];
				if (cnt == k) {
					resx = x;
					resy = y;
				}
				map[x][y] = cnt++;
			}
			stage++;
			for (int j = 0; j < i; j++) {
				x = x + dx[stage % 4];
				y = y + dy[stage % 4];
				if (cnt == k) {
					resx = x;
					resy = y;
				}
				map[x][y] = cnt++;
			}
			stage++;
		}

		for (int i = 1; i < n; i++) {
			x = x + dx[stage % 4];
			y = y + dy[stage % 4];
			if (cnt == k) {
				resx = x;
				resy = y;
			}
			map[x][y] = cnt++;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}

		cout << resx + 1 << " " << resy + 1;

		return 0;
	}
}
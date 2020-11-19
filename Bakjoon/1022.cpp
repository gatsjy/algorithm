#include <bits/stdc++.h>

// 2020-11-16, 한주안, 느낀점.. 
// 좌표 이용법에 대해서 다시 공부해야 할 듯...
using namespace std;

namespace _1022 {
	int m[50][5] = { 0, };
	int r1, c1, r2, c2;

	int calLength(int n) {
		return n > 0 ? calLength(n / 10) + 1 : 1;
	}

	int main() {
		cin >> r1 >> c1 >> r2 >> c2;

		int MAX = max(max(abs(r1), abs(c1)), max(abs(r2), abs(c2)));
		// 하나씩 증가해 갈 수
		int val = 1;
		if (r1 <= 0 && c1 <= 0 && r2 >= 0 && c2 >= 0) {
			m[0 - r1][0 - c1] = val;
		}
		int max_val = -1;

		int cnt = 0; // 몇번째 카운트인지 측정
		int y = 0, x = 0;
		for (int i = 1; i <= MAX + 1; i++) {
			for (int j = 1; j <= 1 + cnt * 2; j++) {
				val++;
				x++;
				if (y >= r1 && x >= c1 && y <= r2 && x <= c2) {
					m[y - r1][x - c1] = val;
					if (max_val < val) max_val = val;
				}
			}
			for (int j = 1; j <= 1 + cnt * 2; j++) {
				val++;
				y--;
				if (y >= r1 && x >= c1 && y <= r2 && x <= c2) {
					m[y - r1][x - c1] = val;
					if (max_val < val) max_val = val;
				}
			}
			for (int j = 1; j <= 2 + cnt * 2; j++) {
				val++;
				x--;
				if (y >= r1 && x >= c1 && y <= r2 && x <= c2) {
					m[y - r1][x - c1] = val;
					if (max_val < val) max_val = val;
				}
			}
			for (int j = 1; j <= 2 + cnt * 2; j++) {
				val++;
				y++;
				if (y >= r1 && x >= c1 && y <= r2 && x <= c2) {
					m[y - r1][x - c1] = val;
					if (max_val < val) max_val = val;
				}
			}
			cnt++;
		}

		int max_val_length = calLength(max_val);

		int h = abs(r2 - r1);
		int w = abs(c2 - c1);

		for (int i = 0; i <= h; i++) {
			for (int j = 0; j <= w; j++) {
				int tmpLength = calLength(m[i][j]);
				if (max_val_length > tmpLength) {
					for (int k = 0; k < max_val_length - tmpLength; k++) {
						cout << " ";
					}
				}
				cout << m[i][j] << " ";
			}
			cout << "\n";
		}
		return 0;
	}
}
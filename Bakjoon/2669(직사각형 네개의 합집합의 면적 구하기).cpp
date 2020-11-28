#include <bits/stdc++.h>

using namespace std;

namespace _2669 {
	int board[101][101];

	int main() {
		for (int i = 0; i < 4; i++) {
			int y_1, x_1, y_2, x_2;
			cin >> y_1 >> x_1 >> y_2 >> x_2;

			for (int j = min(y_1, y_2); j < max(y_1, y_2); j++) {
				for (int k = min(x_1, x_2); k < max(x_1, x_2); k++) {
					board[j][k]++;
				}
			}
		}

		int res = 0;
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				if (board[i][j] > 0) res++;
			}
		}

		cout << res;

		return 0;
	}
}

#include <bits/stdc++.h>

using namespace std;

namespace _1780 {
	int paper[3];
	int board[2200][2200]; //3^7은 2187
	int N, input;

	bool isSame(int y, int x, int size) {
		int start = board[y][x];
		for (int i = y; i < y + size; i++) {
			for (int j = x; j < x + size; j++) {
				if (start != board[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	void divide(int y, int x, int size) {

		// 범위의 모든 수가 같은가?
		if (isSame(y, x, size)) {
			paper[board[y][x]]++;
		}
		else {
			size /= 3;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					divide(y + size * i, x + size * j, size);
				}
			}
		}
	}

	int main() {
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> input;
				board[i][j] = input + 1;
			}
		}

		divide(0, 0, N);

		return 0;
	}
}

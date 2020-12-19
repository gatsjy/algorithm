#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <cstring>

using namespace std;

namespace _16505 {
	// k번째 도미노가 쓰러진다, k-1번째 도미노가 쓰러진다.... 2번째 도미노가 쓰러진다.. 1번째 도미노가 쓰러진다.
	int n;
	int board[1500][1500];
	int pow_2(int cnt) {
		if (cnt == 0) return 1;
		return 2 * pow_2(cnt - 1);
	};

	void func(int x, int y, int cnt) {
		if (cnt == 0) {
			return;
		}
		if (cnt == 1) {
			board[x][y] = 1;
			board[x][y + 1] = 1;
			board[x + 1][y] = 1;
			return;
		}
		func(x, y, cnt - 1);
		func(x, y + pow_2(cnt - 1), cnt - 1);
		func(x + pow_2(cnt - 1), y, cnt - 1);
	};

	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n;

		if (n == 0) {
			cout << "*";
		}
		else {
			func(0, 0, n);
			func(0, pow_2(n), n);
			func(pow_2(n), 0, n);
			for (int i = 0; i < pow_2(n); i++) {
				for (int j = 0; j < pow_2(n) - i; j++) {
					if (board[i][j] == 1) {
						cout << "*";
					}
					else {
						cout << " ";
					}
				}
				if (i != pow_2(n) - 1) {
					cout << "\n";
				}
			}
		}

		memset(board, 0, sizeof(board)); // 배열 초기화?
		return 0;
	}
}
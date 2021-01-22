#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <set>

using namespace std;
namespace _2210 {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	int board[6][6];
	set<int> ss;
	vector<char> a;
	int ch[6][6];
	void dfs(int x, int y, int level, int sum) {
		if (level == 5) {
			ss.insert(sum);
			//cout << sum << "\n";
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
				dfs(nx, ny, level + 1, sum * 10 + board[nx][ny]);
			}
		}
	}

	int main() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				dfs(i, j, 0, board[i][j]);
			}
		}

		cout << ss.size();
		return 0;
	}
}
#include <bits/stdc++.h>

using namespace std;

int n; // n은 2이상 100이하의 정수
int visited[101][101], a[101][101];
int max_height = -2147000000;
int input;
int max_cnt = 0; // 물에 잠기지 않는 최대 갯수
int ret = 0;
int res = 0;
int x, y;
int dy[4] = {-1,0,1,0};
int dx[4] = { 0,1,0,-1 };

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (!visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			a[i][j] = input;
			max_height = max(max_height, input);
		}
	}

	for (int i = 1; i < max_height; i++) {
		ret = 0;
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i >= a[j][k]) visited[j][k] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) {
					dfs(i, j);
					ret++;
				}
			}
		}
		if (ret > max_cnt) {
			max_cnt = ret;
			res = i;
		}
	}

	cout << res;


	return 0;
}
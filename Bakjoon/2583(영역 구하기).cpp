#include <bits/stdc++.h>

using namespace std;
#define y1 aaaa

int m, n, k;
int d;
int cnt;
int a[101][101], visited[101][101];

vector<int> res;

int y2, y1, x2, x1;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void dfs(int y, int x) {
	visited[y][x] = 1;
	cnt += 1;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (!visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> m >> n >> k;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 1;
		}
	}

	for (int d = 0; d < k; d++) {
		// y1, x1 -> 왼쪽아래
		// y2, x2 -> 오른쪽위
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				visited[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				res.push_back(cnt);
			}
		}
	}
	sort(res.begin(), res.end());

	cout << res.size() << "\n";
	for (int i = 0; i < res.size() ; i++) {
		cout << res[i] << " ";
	}
	return 0;
}
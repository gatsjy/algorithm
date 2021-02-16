#include <bits/stdc++.h>

using namespace std;

#define MAX 31
#define INF 2147000000

int n, m, h;
int ch[MAX][MAX];
int res = INF;
bool isOk() {
	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int j = 1; j <= h; j++) {
			if (ch[cur][j]) cur = cur + 1;
			else if (ch[cur - 1][j]) cur = cur - 1;
		}
		if (cur != i) return false;
	}
	return true;
}
void dfs(int idx, int cnt) {
	if (cnt >= 4) return;
	if (isOk()) {
		res = min(res, cnt);
		return;
	}
	for (int i = idx; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			// 입력으로 주어지는 가로선이 서로 연속하는 경우는 없다.
			if (ch[i][j]) continue;
			if (ch[i - 1][j]) continue;
			if (ch[i + 1][j]) continue;
			ch[i][j] = 1;
			dfs(i, cnt + 1);
			ch[i][j] = 0;
		}
	}
}
int main() {
	cin >> n >> m >> h;

	int s, e;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		ch[s][e] = 1;
	}
	dfs(1, 0);
	if (res == INF) res = -1;
	cout << res;
	return 0;
}
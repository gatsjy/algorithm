#include <bits/stdc++.h>

using namespace std;

int n, m;
int vis[10][10];
int a[10][10];
vector<pair<int, int>> v;
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
void dfs(int x, int y) {
	if (a[x][y] == 1 || vis[x][y]) return;
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		dfs(nx, ny);
	}
}
int solve() {
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2) dfs(i, j);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && a[i][j] == 0)ans++;
		}
	}
	return ans;
}
int main() {

	// 1. ����? ���� ����� ��� ����Ǽ��� Ȯ���Ѵ�..
	// 2. ȿ��? �����ϰ� �Ǵ��� �ȵǴ��� Ȯ��? ������ Ȯ���ؾ� �մϴ�.
	// 64c3 36600 -> ����� ����� �� �ִ�. 1���̳� 10�� �̻�... 

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (!a[i][j]) v.push_back({ i,j }); // ���� ����� �ĺ���
		}
	}

	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
				ans = max(ans, solve());
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
			}
		}
	}

	cout << ans;
	return 0;
}
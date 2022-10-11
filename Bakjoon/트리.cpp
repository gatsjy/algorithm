#include <bits/stdc++.h>

using namespace std;
int mp[51][51];
int n, m;
int a, b, c;

void dfs(int v) {
	int i;
	if (v == n) {
		cnt++;
	}
	else {
		for (i = 0; i < map[v].size(); i++) {
			if (!ch[map[v][i]]) {
				ch[map[v][i]] = 1;
				dfs(map[v][i]);
				ch[map[v][i]] = 0;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mp[a][b] = c;
	}
	return 0;
}
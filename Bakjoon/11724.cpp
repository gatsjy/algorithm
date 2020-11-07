#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> v;
vector<bool> ch;
int n, m, a, b, cnt = 0;

void dfs(int idx) {
	ch[idx] = true;
	for(int i = 0; i < v[idx].size(); i++){
		if (!ch[v[idx][i]]) {
			dfs(v[idx][i]);
		}
	}
}
int main() {
	cin >> n >> m;

	v =vector<vector<int>>(n + 1);
	ch = vector<bool>(n + 1);
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!ch[i] && v[i].size() > 0) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;

}
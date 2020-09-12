#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int t;
vector<bool> ch;
vector<vector<int>> v;

int bfs(vector<vector<int>> v) {
	queue<int> q;
	q.push(1);
	int ans = -1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (!ch[cur]) {
			ch[cur] = true;
			ans++;
			for (int i = 0; i < v[cur].size(); i++) {
				int togo = v[cur][i];
				if (!ch[togo]) {
					q.push(togo);
				}
			}
		}
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	;
	cin >> t;

	while (t--) {
		int c, m;
		cin >> c >> m;
		ch = vector<bool>(c + 1);
		v = vector<vector<int>>(c + 1);

		for (int i = 0; i < m; i++) {
			int from, to;
			cin >> from >> to;
			v[from].push_back(to);
			v[to].push_back(from);
		}
		
		cout << bfs(v) << endl;
	}
}
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>

namespace _68 {
#define x first
#define y second
	using namespace std;
	int ch[30], cnt = 0, n, cost = 2147000000;
	vector<pair<int, int> > map[30];
	void DFS(int v, int sum) {
		if (v == n) {
			cost = min(cost, sum);
		}
		else {
			for (int i = 0; i < map[v].size(); i++) {
				if (ch[map[v][i].first] == 0) {
					ch[map[v][i].first] = 1;
					DFS(map[v][i].first, sum + map[v][i].second);
					ch[map[v][i].first] = 0;
				}
			}
		}
	}

	int main() {
		int m, i, a, b, c;
		cin >> n >> m;
		for (i = 1; i <= m; i++) {
			cin >> a >> b >> c;
			map[a].push_back(make_pair(b, c));
		}
		ch[1] = 1;
		DFS(1, 0);
		printf("%d\n", cost);
		return 0;
	}
}
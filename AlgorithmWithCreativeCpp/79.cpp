#include <bits/stdc++.h>

using namespace std;

int ch[30];

struct edge {
	int e;
	int val;
	edge(int a, int b) {
		e = a;
		val = b;
	}
	bool operator<(const edge& b)const{
		return val > b.val;
	}
};

int main() {
	priority_queue<edge> pq;
	vector<pair<int, int>> map[30];
	int n, m;
	cin >> n >> m;
	int a, b, c;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	pq.push(edge(1, 0));
	int res = 0;
	while (!pq.empty()) {
		edge tmp = pq.top();
		pq.pop();
		int v = tmp.e;
		int cost = tmp.val;
		if (ch[v] == 0) {
			res += cost;
			ch[v] = 1;
			for (int i = 0; i < map[v].size(); i++) {
				pq.push(edge(map[v][i].first, map[v][i].second));
			}
		}
	}
	cout << res;
}
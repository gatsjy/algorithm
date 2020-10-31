#include <bits/stdc++.h>

using namespace std;

namespace _79 {
	int ch[30];

	struct city {
		int v;
		int cost;
		city(int a, int b) {
			v = a;
			cost = b;
		}
		bool operator<(const city& b)const {
			return cost > b.cost;
		}
	};
	int main() {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> v[30];
		int a, b, c;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			v[a].push_back(make_pair(b, c));
			v[b].push_back(make_pair(a, c));
		}
		priority_queue<city> pq;
		pq.push(city(1, 0));
		int res = 0;
		while (!pq.empty()) {
			city tmp = pq.top();
			pq.pop();
			int next = tmp.v;
			int c = tmp.cost;
			if (ch[next] == 0) { // 그냥 한번 더 감싸면 끝나는 일이다 ㅋㅋㅋ
				res += c;
				ch[next] = 1;
				for (int i = 0; i < v[next].size(); i++) {
					if (ch[v[next][i].first] == 0) {
						pq.push(city(v[next][i].first, v[next][i].second));
					}
				}
			}
		}
		cout << res;
		return 0;
	}
}
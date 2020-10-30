#include <bits/stdc++.h>

using namespace std;

namespace _78 {
	int unf[1001];

	int Find(int v) {
		if (unf[v] == v) return v;
		else Find(unf[v]);
	}

	void Union(int a, int b) {
		a = Find(a);
		b = Find(b);
		if (a != b) unf[a] = b;
	}
	struct city {
		int start;
		int end;
		int cost;
		city(int a, int b, int c) {
			start = a;
			end = b;
			cost = c;
		}
		bool operator<(city& b) {
			return cost < b.cost;
		}
	};
	int main() {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			unf[i] = i;
		}
		int a, b, c;
		vector<city> v;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			v.push_back(city(a, b, c));
		}
		sort(v.begin(), v.end());
		int sum = 0;
		for (int i = 0; i < m; i++) {
			int aa = Find(v[i].start);
			int bb = Find(v[i].end);
			if (aa != bb) {
				Union(aa, bb);
				sum += v[i].cost;
			}
		}
		cout << sum;
		return 0;
	}
}
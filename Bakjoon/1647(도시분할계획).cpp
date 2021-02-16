#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <string>
using namespace std;

namespace _1647 {
#define MAX 100001
#define INF -2147000000

	int unf[MAX];

	struct Edge {
		int s;
		int e;
		int val;
		Edge(int a, int b, int c) {
			s = a;
			e = b;
			val = c;
		}
		bool operator<(const Edge& b) const {
			return val < b.val;
		}
	};

	int Find(int v) {
		if (v == unf[v]) return v;
		else return unf[v] = Find(unf[v]);
	}

	void Union(int a, int b) {
		a = Find(a);
		b = Find(b);
		if (a != b) unf[a] = b;
	}
	// h-> home
	vector<Edge> h;
	int res = 0;
	int n, m, a, b, c;
	int cost_max = INF;
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			unf[i] = i;
		}

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			h.push_back(Edge(a, b, c));
		}

		sort(h.begin(), h.end());

		for (int i = 0; i < m; i++) {
			int fs = Find(h[i].s);
			int fe = Find(h[i].e);
			if (fs != fe) {
				res += h[i].val;
				if (h[i].val > cost_max) cost_max = h[i].val;
				Union(fs, fe);
			}
		}
		cout << res - cost_max;
		return 0;
	}
}

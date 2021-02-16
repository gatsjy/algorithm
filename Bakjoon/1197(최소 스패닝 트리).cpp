#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <string>

using namespace std;

namespace _1197 {
	//https://www.acmicpc.net/problem/1197

#define MAX 10001
#define INF 2147000000

	int unf[MAX];
	int ch[MAX];
	struct Edge {
		int s;
		int e;
		int val;
		Edge(int a, int b, int c) {
			s = a;
			e = b;
			val = c;
		}
		bool operator<(const Edge& b)const {
			return val < b.val;
		}
	};

	int Find(int v) {
		if (v == unf[v])return v;
		else return unf[v] = Find(unf[v]);
	}

	void Union(int a, int b) {
		a = Find(a);
		b = Find(b);
		if (a != b) unf[a] = b;
	}

	int n, m, a, b, c;
	int res = 0;
	int main() {

		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			unf[i] = i;
		}
		vector<Edge> ed;
		for (int i = 1; i <= m; i++) {
			cin >> a >> b >> c;
			ed.push_back(Edge(a, b, c));
		}
		sort(ed.begin(), ed.end());
		for (int i = 0; i < m; i++) {
			int fa = Find(ed[i].s);
			int fb = Find(ed[i].e);
			if (fa != fb) {
				res += ed[i].val;
				Union(ed[i].s, ed[i].e);
			}
		}
		cout << res;
		return 0;
	}
}
#include <bits/stdc++.h>

using namespace std;
namespace _78 {
	int unf[101];

	struct city {
		int start;
		int end;
		int val;
		city(int a, int b, int c) {
			start = a;
			end = b;
			val = c;
		};
		bool operator<(city& b) {
			return val < b.val;
		}
	};

	int Find(int v) {
		if (v == unf[v])return v;
		else return Find(unf[v]);
	}
	void Union(int a, int b) {
		a = Find(a);
		b = Find(b);
		if (a != b) unf[a] = b;
	}

	int main() {
		int n, m, a, b, c;
		cin >> n >> m;
		vector<city> v;
		for (int i = 1; i <= n; i++) {
			unf[i] = i;
		}
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			v.push_back(city(a, b, c));
		}
		sort(v.begin(), v.end());
		int res = 0;
		for (int i = 0; i < v.size(); i++) {
			int aa = Find(v[i].start);
			int bb = Find(v[i].end);
			if (aa != bb) {
				Union(v[i].start, v[i].end);
				res += v[i].val;
			}
		}
		cout << res;
		return 0;
	}
}
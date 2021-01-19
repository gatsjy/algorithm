#include <bits/stdc++.h>

using namespace std;

namespace _1431 {
	int n;

	vector<string> v;

	bool cmp(string& a, string& b) {
		if (a.size() != b.size()) {
			return a.size() < b.size();
		}
		int asum = 0;
		int bsum = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= '0' && a[i] <= '9') {
				asum += a[i] - '0';
			}
			if (b[i] >= '0' && b[i] <= '9') {
				bsum += b[i] - '0';
			}
		}
		if (asum != bsum) return asum < bsum;
		return a < b;
	}
	int main() {
		cin >> n;
		v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < n; i++) {
			cout << v[i] << "\n";
		}
		return 0;
	}
}
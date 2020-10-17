#include <bits/stdc++.h>

using namespace std;

namespace _4 {
	void main() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cout << v.back() - v[0];
	}
}
#include <bits/stdc++.h>

using namespace std;

namespace _45 {
	int main() {

		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		int cnt = 0;
		int cur = 0;
		int ch = 0;
		while (ch != n - 1) {
			if (cur == n) cur = 0;
			if (a[cur] == 0) {
				cnt++;
			}
			if (cnt == k) {
				a[cur] = 1;
				cnt = 0;
				ch++;
			}
			cur++;
		}

		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				cout << i + 1;
				break;
			}
		}
		return 0;
	}
}
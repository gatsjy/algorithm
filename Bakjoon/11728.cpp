#include <bits/stdc++.h>

using namespace std;

namespace _11728 {
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int n, m;
		cin >> n >> m;
		vector<int> ans(n + m);
		/*vector<int> a(n);
		vector<int> b(m);
		vector<int> ans(n + m);

		int p1 = 0, p2 = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int idx = 0;
		while (p1 < n && p2 < m) {
			if (a[p1] < b[p2]) {
				ans[idx++] = a[p1++];
			}
			else {
				ans[idx++] = b[p2++];
			}
		}

		if (p1 < n) {
			while (p1 < n) {
				ans[idx++] = a[p1++];
			}
		}

		if (p2 < m) {
			while (p2 < n) {
				ans[idx++] = b[p2++];
			}
		}*/

		for (int i = 0; i < n + m; i++) {
			cin >> ans[i];
		}

		sort(ans.begin(), ans.end());
		for (int i = 0; i < n + m; i++) {
			cout << ans[i] << " ";
		}
		return 0;
	}
}

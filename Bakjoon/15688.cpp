#include <bits/stdc++.h>

using namespace std;

namespace _15688 {
	int a[1000001];

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			cout << a[i] << "\n";
		}
		return 0;
	}
}

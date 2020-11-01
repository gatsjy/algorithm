#include <bits/stdc++.h>

using namespace std;

namespace _18883 {
	int main() {
		int n, m;
		cin >> n >> m;
		int cnt = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j == m - 1) {
					cout << cnt++;
				}
				else {
					cout << cnt++ << " ";
				}

			}
			cout << endl;
		}
		return 0;
	}
}
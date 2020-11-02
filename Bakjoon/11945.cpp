#include <bits/stdc++.h>

using namespace std;

namespace _11945 {
	char a[11][11];
	int main() {
		int n, m;
		cin >> n >> m;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < m; j++) {
				a[i][j] = s[j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				cout << a[i][j];
			}
			cout << endl;
		}
		return 0;
	}
}


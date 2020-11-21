#include <bits/stdc++.h>

using namespace std;

namespace _1783 {
	int main() {

		int n, m;
		cin >> n >> m;

		if (n == 1) {
			cout << 1;
		}
		else if (n == 2) {
			cout << min(4, (m + 1) / 2);
		}
		else {
			if (m <= 6) {
				cout << min(4, m);
			}
			else if (m > 6) {
				cout << m - 2;
			}
		}
		return 0;
	}
}

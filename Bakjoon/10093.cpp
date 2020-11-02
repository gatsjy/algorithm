#include <bits/stdc++.h>

using namespace std;

namespace _10093 {
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		long long n, m;
		cin >> n >> m;
		if (n > m) {
			swap(n, m);
		}
		if (n != m) {
			cout << m - n - 1 << "\n";
			for (long long i = n + 1; i < m; i++) {
				cout << i << " ";
			}
			cout << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}

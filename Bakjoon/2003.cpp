#include <bits/stdc++.h>

using namespace std;

namespace _2003 {
	int main() {

		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = i; j < n; j++) {
				sum += a[j];
				if (sum > m) {
					break;
				}
				else {
					if (sum == m) {
						cnt++;
					}
				}
			}
		}
		cout << cnt;
		return 0;
	}
}
#include <bits/stdc++.h>

using namespace std;

namespace _48 {
	int main() {

		int cnt = 9;
		while (cnt--) {
			vector<int> a(9);
			int sum = 0;
			for (int i = 0; i < 9; i++) {
				cin >> a[i];
				sum += a[i];
			}
			sort(a.begin(), a.end());
			cout << sum / 9 << " " << a[4] << endl;
		}
		return 0;
	}
}
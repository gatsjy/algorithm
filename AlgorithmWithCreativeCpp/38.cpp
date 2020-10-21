#include <bits/stdc++.h>

using namespace std;

namespace _38 {
	int main() {
		int n;
		cin >> n;
		vector<int> a(n);

		int input;
		for (int i = 1; i <= n; i++) {
			cin >> input;
			int tmp = input;
			for (int j = 0; j < n; j++) {
				if (a[j] != 0) continue;
				if (tmp == 0) {
					a[j] = i;
					break;
				}
				if (a[j] == 0) tmp--;
			}
		}

		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		return 0;
	}
}

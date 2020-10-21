#include <bits/stdc++.h>

using namespace std;

namespace _42 {
	int main() {
		int n, target;
		cin >> n >> target;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int ldx = 0;
		int rdx = n - 1;
		int mid = 0;
		while (ldx < rdx) {
			mid = (ldx + rdx) / 2;
			if (a[mid] < target) {
				ldx = mid + 1;
			}
			else {
				rdx = mid - 1;
			}
		}
		cout << ldx + 1;
		return 0;
	}
}

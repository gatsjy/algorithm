#include <bits/stdc++.h>

using namespace std;
namespace _52 {
	int a[1501] = { 0, };

	int main() {
		int p2 = 1, p3 = 1, p5 = 1;
		int n;
		cin >> n;
		a[1] = 1;
		for (int i = 2; i <= n; i++) {
			int minv = min(a[p2] * 2, a[p3] * 3);
			minv = min(minv, a[p5] * 5);
			if (minv == a[p2] * 2) {
				a[i] = a[p2] * 2;
				p2++;
			}
			if (minv == a[p3] * 3) {
				a[i] = a[p3] * 3;
				p3++;
			}
			if (minv == a[p5] * 5) {
				a[i] = a[p5] * 5;
				p5++;
			}
		}
		cout << a[n];
		return 0;
	}
}

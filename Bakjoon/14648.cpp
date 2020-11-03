#include <bits/stdc++.h>

using namespace std;

namespace _14648 {
	typedef long long ll;
	int main() {

		int n, m;
		cin >> n >> m;
		vector<ll> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int a, b, c, d, e;
		while (m--) {
			cin >> a;
			if (a == 1) {
				cin >> b >> c;
				ll sum = 0;
				for (int i = b - 1; i < c; i++) {
					sum += v[i];
				}
				// 2와 5의 자리를 바꾼다.
				ll temp = v[c - 1];
				v[c - 1] = v[b - 1];
				v[b - 1] = temp;
				cout << sum << endl;
			}
			else if (a == 2) {
				cin >> b >> c >> d >> e;
				// 1 3 2 4
				ll sum1 = 0;
				ll sum2 = 0;
				for (int i = b - 1; i < c; i++) {
					sum1 += v[i];
				}
				for (int i = d - 1; i < e; i++) {
					sum2 += v[i];
				}
				cout << sum1 - sum2 << endl;
			}
		}
		return 0;
	}
}
#include <bits/stdc++.h>

using namespace std;

namespace _23 {
	int main() {
		int N;
		cin >> N;
		vector<int> a(N);
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		int idx = 0;
		int cnt = 1;
		int res = -2147000000;
		for (int i = 0; i < N - 1; i++) {
			if (a[i] <= a[i + 1]) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			res = max(cnt, res);
		}

		cout << res;
		return 0;
	}
}

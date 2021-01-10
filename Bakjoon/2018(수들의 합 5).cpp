#include <bits/stdc++.h>

using namespace std;

namespace _2018 {
	typedef long long ll;

	int main() {
		int n;
		cin >> n;

		int res = 0;
		int num = 1;

		while (1) {
			ll tmp = 1LL * (num * (num + 1) / 2);
			if (tmp > n) break;
			if ((n - tmp) % num == 0) res++;
			num++;
		}

		cout << res;
		return 0;
	}
}
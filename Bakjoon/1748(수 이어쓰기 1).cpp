#include <bits/stdc++.h>

using namespace std;

namespace _1748 {
	int n, sum = 0, cnt = 1, digit = 9, res = 0;
	int main() {
		cin >> n;

		while (sum + digit < n) {
			sum = sum + digit;
			res = res + (cnt * digit);
			cnt++;
			digit = digit * 10;
		}
		res = res + ((n - sum) * cnt);
		cout << res;
		return 0;
	}
}

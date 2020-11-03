#include <bits/stdc++.h>

namespace _2460 {
	using namespace std;
	int res = -1;
	int guest = 0;
	int main() {
		int a, b;
		for (int i = 0; i < 10; i++) {
			cin >> a >> b;
			guest = guest - a + b;
			if (res < guest) {
				res = guest;
			}
		}
		cout << res;
		return 0;
	}
}
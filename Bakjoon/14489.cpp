#include <bits/stdc++.h>

using namespace std;

namespace _14489 {
	int main() {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b >= 2 * c) {
			cout << a + b - 2 * c;
		}
		else {
			cout << a + b;
		}
		return 0;
	}
}

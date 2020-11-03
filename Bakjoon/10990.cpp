#include <bits/stdc++.h>

using namespace std;

namespace _10990{
	int main() {

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int k = n - i; k > 0; k--) {
				cout << " ";
			}
			cout << "*";
			for (int j = 0; j < 2 * (i - 1) - 1; j++) {
				cout << " ";
			}
			if (i != 1) {
				cout << "*";
			}
			cout << endl;
		}
		return 0;
	}
}

#include <bits/stdc++.h>
using namespace std;

int c, n;
int main() {
	cin >> c;
	while (c--) {
		cin >> n;
		if (n == 1) {
			cout << "#" << "\n";
			continue;
		}

		for (int i = 0; i < n; i++) {
			cout << "#";
		}
		cout << "\n";
		
		for (int i = 0; i < n - 2; i++) {
			cout << "#";
			for (int j = 0; j < n - 2; j++) {
				cout << "J";
			}
			cout << "#" << "\n";
		}

		for (int i = 0; i < n; i++) {
			cout << "#";
		}
		cout << "\n";
	}
	return 0;
}
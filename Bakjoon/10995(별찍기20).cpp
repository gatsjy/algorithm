#include <bits/stdc++.h>

using namespace std;

int n;
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) cout << " ";
		for (int j = 1; j <= n; j++) {
			cout << "* ";
		}
		cout << "\n";
	}
	return 0;
}
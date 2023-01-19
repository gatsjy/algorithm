#include <bits/stdc++.h>

using namespace std;


int n;
int a[101];
int b[101];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	// 1: 가위 2: 바위 3: 보
	// 11
	// 12
	// 13
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			cout << "D" << "\n";
		}
		else if (a[i] == 1 && b[i] == 3) {
			cout << "A" << "\n";
		}
		else if (a[i] == 1 && b[i] == 2) {
			cout << "B" << "\n";
		}
		else if (a[i] == 2 && b[i] == 1) {
			cout << "A" << "\n";
		}
		else if (a[i] == 2 && b[i] == 3) {
			cout << "B" << "\n";
		}
		else if (a[i] == 3 && b[i] == 1) {
			cout << "B" << "\n";
		}
		else if (a[i] == 3 && b[i] == 2) {
			cout << "A" << "\n";
		}
	}

	return 0;
}
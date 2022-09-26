#include <bits/stdc++.h>

using namespace std;

int n;
int a[81][81];

string go(int y, int x, int cnt) {
	return "";
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &a[i][j]);
		}
	}

	// 4번의 쿼드트리 로직을 발생시킨다.
	go(0, 0, n / 2); // (0,0) + 4
	go(0 + n / 2, 0, n / 2); // (4, 0) + 4;
	go(0, 0 + n / 2, n / 2); // (0, 4) + 4;
	go(n / 2, n / 2, n / 2); // (4, 4) + 4;
	return 0;
}
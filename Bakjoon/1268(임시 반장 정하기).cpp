#include <bits/stdc++.h>

using namespace std;

int n;
int a[1004][1004];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int mx = -2147000000;
	int res = 0;
	for (int i = 0; i < n; i++) {
		// i는 학생 번호
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			// 당시 학년의 반
			int tmp = a[i][j];
			for (int k = 0; k < n; k++) {
				if (i == k) continue;
				if (tmp == a[k][j]) {
					cnt++;
				}
			}
		}
		if (mx < cnt) {
			mx = cnt;
			res = i;
		}
	}

	cout << res+1;
	return 0;
}
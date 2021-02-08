#include <bits/stdc++.h>

using namespace std;

namespace _시각 {
	int h, cnt = 0;

	// 항상 간단하게 생각하는 습관을 가지자!!
	bool check(int hh, int mm, int ss) {
		if (hh % 10 == 3 || mm % 10 == 3 || mm / 10 == 3 || ss / 10 == 3 || ss % 10 == 3) return false;
		return true;
	}

	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> h;

		for (int i = 0; i <= h; i++) {
			for (int j = 0; j < 60; j++) {
				for (int k = 0; k < 60; k++) {
					//cout << i << ":" << j << ":" << k << "\n";
					if (!check(i, j, k)) cnt++;
				}
			}
		}

		cout << cnt;

		return 0;
	}
}

#include <bits/stdc++.h>

using namespace std;

namespace _�ð� {
	int h, cnt = 0;

	// �׻� �����ϰ� �����ϴ� ������ ������!!
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

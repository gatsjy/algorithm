#include <bits/stdc++.h>

using namespace std;
namespace _14225 {
	int n;
	vector<int> a;
	bool res[1 << 22] = { 0, };

	int main() {
		cout << (1 << 22);
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < (1 << n); i++) {
			// 부분 집합 뽑아내기
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					sum += a[j];
				}
			}

			res[sum] = 1;
		}

		for (int i = 1; i <= 2000000; i++) {
			if (res[i] == 0) {
				cout << i;
				break;
			}
		}
		return 0;
	}
}
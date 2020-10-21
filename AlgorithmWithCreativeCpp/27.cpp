#include <bits/stdc++.h>

using namespace std;

namespace _27 {
	int main() {
		int n;
		cin >> n;
		vector<int> ch(n + 1);
		// 소인수 분해를 진행합니다.
		for (int i = 2; i <= n; i++) {
			int tmp = i;
			int j = 2;
			while (1) {
				if (tmp % j == 0) {
					ch[j]++;
					tmp /= j;
				}
				else {
					j++;
				}
				if (tmp == 1) break;
			}
		}

		cout << n << "! = ";
		for (int i = 2; i < n + 1; i++) {
			if (ch[i] > 0) {
				cout << ch[i] << " ";
			}
		}
		return 0;
	}
}

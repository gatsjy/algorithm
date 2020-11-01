#include <bits/stdc++.h>

using namespace std;

namespace _14656 {
	int main() {

		int n, m;
		cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> m;
			if (m != i)cnt++;
		}
		cout << cnt;
		return 0;
	}
}

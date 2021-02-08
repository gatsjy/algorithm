#include <bits/stdc++.h>

using namespace std;

namespace _모험가길드 {
	int n;
	int a[100001];
	int cnt = 0;
	int main() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);

		int groupcnt = 0;
		for (int i = 0; i < n; i++) {
			groupcnt += 1;
			if (groupcnt >= a[i]) {
				cnt++;
				groupcnt = 0;
			}
		}

		cout << cnt;

		return 0;
	}
}
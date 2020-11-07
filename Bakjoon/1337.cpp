#include <bits/stdc++.h>

using namespace std;

namespace _1337 {
	int a[10001];
	map<int, bool> ch;

	int main() {

		int n, input;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ch[a[i]] = true;
		}
		sort(a, a + n);

		int res = 5;
		for (int i = 0; i < n; i++) {

			// 가상의 배열을 만들어서 map을 하나씩 돌린다.
			int idx = a[i];
			int cnt = 4;
			for (int j = idx + 1; j < idx + 5; j++) {
				if (ch[j]) cnt--;
			}
			res = min(cnt, res);
		}

		cout << res;

		return 0;
	}
}
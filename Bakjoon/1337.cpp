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

			// ������ �迭�� ���� map�� �ϳ��� ������.
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
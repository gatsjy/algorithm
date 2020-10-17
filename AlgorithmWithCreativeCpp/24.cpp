#include <bits/stdc++.h>

using namespace std;

namespace _24 {
	int main() {
		int N;
		cin >> N;
		vector<int> ch(N);
		vector<int> a(N);
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < N - 1; i++) {
			ch[i] = abs(a[i] - a[i + 1]);
		}

		bool flag = true;
		sort(ch.begin(), ch.end());
		for (int i = 1; i < N; i++) {
			if (ch[i] != i) flag = false;
		}
		if (flag) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		return 0;
	}
}

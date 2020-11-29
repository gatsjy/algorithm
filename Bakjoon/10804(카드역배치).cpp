#include <bits/stdc++.h>

namespace _10804 {
	using namespace std;

	vector<int> a(21);
	int main() {
		for (int i = 1; i <= 20; i++) {
			a[i] = i;
		}

		for (int i = 0; i < 10; i++) {
			int start, end;
			cin >> start >> end;
			reverse(a.begin() + start, a.begin() + end + 1);
		}

		for (int i = 1; i <= 20; i++) {
			cout << a[i] << " ";
		}
		return 0;
	}
}

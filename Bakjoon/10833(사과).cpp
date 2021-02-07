#include <bits/stdc++.h>

using namespace std;

namespace _10833 {
	int student, apple;
	int main() {
		int n;
		int res = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> student >> apple;
			int divide = apple / student;
			if (divide != 0) {
				res += (apple % (student * divide));
			}
			else {
				res += apple;
			}
		}

		cout << res;
		return 0;
	}
}

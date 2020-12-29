#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace _1476 {
	int e, s, m;

	int main() {
		cin >> e >> s >> m;

		int res = e;

		while (1) {
			if ((res % 28 == s % 28) && (res % 19 == m % 19)) {
				break;
			}
			res += 15;
		}
		cout << res;
		return 0;
	}
}
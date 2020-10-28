#include <bits/stdc++.h>

using namespace std;

namespace _1259 {
	int main() {
		int n;
		while (cin >> n) {
			if (n == 0) return 0;
			string s = to_string(n);
			bool flag = true;
			for (int i = 0; i < s.size() / 2; i++) {
				if (s[i] != s[s.size() - 1 - i]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << "yes" << endl;
			}
			else {
				cout << "no" << endl;
			}
		}
		return 0;
	}
}
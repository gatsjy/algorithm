#include <bits/stdc++.h>

using namespace std;

namespace _1747 {
	int n;
	bool sosu[1004000] = { 0,1 };
	long long a, b;

	bool isPalen(string s) {
		for (int j = 0; j < s.size() / 2; j++) {
			if (s[j] != s[s.size() - 1 - j]) {
				return false;
			}
		}
		return true;
	}
	int main() {
		ios_base::sync_with_stdio(0);
		cout.tie(0);
		cout.tie(0);

		cin >> n;

		for (int i = 2; i <= 1004000; i++) {
			for (int j = 2; i * j <= 1004000; j++) {
				if (!sosu[i * j]) sosu[i * j] = 1;
			}
		}

		for (int i = n; i <= 1004000; i++) {
			if (!sosu[i]) {
				string s = to_string(i);
				if (isPalen(s)) {
					cout << s;
					break;
				}
			}
		}
		return 0;
	}
}
#include <bits/stdc++.h>

using namespace std;

namespace _곱하기혹은더하기 {
	string s;

	int main() {
		cin >> s;
		int result = s[0] - '0';

		for (int i = 1; i < s.size(); i++) {
			if (result <= 1 || s[i] - '0' <= 1) {
				result += s[i] - '0';
			}
			else {
				result *= s[i] - '0';
			}
		}
		cout << result;
		return 0;
	}
}